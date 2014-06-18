/*
 * Note: The internal type isn't visible to the dynamic binder.
 * 
 * Created a namespace
 * Added three imports to the namespace
 * Create a class
 * Added a memeber field to the class
 * Attached the class to the namespace
 * Created a constructor
 * Created an assignment expression
 * Added the assignment expression to the constructor
 * ...
 */

using System;
using System.CodeDom;
using System.CodeDom.Compiler;
using System.Text;
using System.IO;
using System.Reflection;
using System.Threading;

namespace ConstructAssemblyStepByStep
{
    class Program
    {
        static void Main(string[] args)
        {
            string code = GenerateCSharpCodeFromNamespace(CreateMimsyNamespace());
            Console.WriteLine(code);

            CodeNamespace mimsyNamespace = CreateMimsyNamespace();
            Console.WriteLine(CompileAndExerciseJubjub(mimsyNamespace, 8, 6, 7, 5, 3, -1, 9));

            Console.Read();
        }


        static string CompileAndExerciseJubjub(CodeNamespace theNamespace, params int[] wabes)
        {
            if (wabes == null || wabes.Length == 0)
                return string.Empty;

            Assembly compiledAssembly = CompileNamespaceToAssembly(theNamespace);
            dynamic bird = InstantiateDynamicType(compiledAssembly, "Mimsy.Jubjub", new object[] { wabes[0] });

            for (int ndx = 1; ndx < wabes.Length; ndx++)
            {
                bird.WabeCount = wabes[ndx];
            }

            return bird.GetWabeCountHistory();
        }

        /// <summary>
        /// 构造一个命名空间
        /// </summary>
        /// <returns>code</returns>
        static CodeNamespace CreateMimsyNamespace()
        {
            // 定义命名空间
            CodeNamespace mimsyNamespace = new CodeNamespace("Mimsy");
            // 添加引用
            mimsyNamespace.Imports.AddRange(new[]
            {
               new CodeNamespaceImport("System"),
               new CodeNamespaceImport("System.Text"),
               new CodeNamespaceImport("System.Collections")
            });

            // 定义类
            CodeTypeDeclaration jubjubClass = new CodeTypeDeclaration("Jubjub")
            {
                TypeAttributes = TypeAttributes.Public  // NotPublic = internal, the internal type isn't visible to the dynamic binder
            };

            // 定义成员字段
            CodeMemberField wabeCountFld = new CodeMemberField(typeof(int), "_wabeCount")
            {
                Attributes = MemberAttributes.Private
            };

            jubjubClass.Members.Add(wabeCountFld);  // 附加字段到类
            mimsyNamespace.Types.Add(jubjubClass);  // 附加类到命名空间

            // 定义实例构造函数
            CodeConstructor jubjubCtor = new CodeConstructor
            {
                Attributes = MemberAttributes.Public
            };

            // 定义参数
            var para = new CodeParameterDeclarationExpression(typeof(int), "wabeCount");
            jubjubCtor.Parameters.Add(para);  // 附加参数到构造函数

            // 添加 ArrayList 字段
            var typerefArrayList = new CodeTypeReference("ArrayList");
            CodeMemberField updatesFld = new CodeMemberField(typerefArrayList, "_updates");
            jubjubClass.Members.Add(updatesFld);

            // 引用 _updates 字段
            var refUpdatesFld = new CodeFieldReferenceExpression(new CodeThisReferenceExpression(), "_updates");
            // 实例化 ArrayList
            var newArrayList = new CodeObjectCreateExpression(typerefArrayList);
            // 赋值
            var assignUpdates = new CodeAssignStatement(refUpdatesFld, newArrayList);
            jubjubCtor.Statements.Add(assignUpdates); // 附加赋值语句到构造函数

            // 引用 _wabeCount 字段
            var refWabeCountFld = new CodeFieldReferenceExpression(new CodeThisReferenceExpression(), "_wabeCount");
            // 定义引用属性(用于赋值时进行判断)
            var refWabeCountProp = new CodePropertyReferenceExpression(new CodeThisReferenceExpression(), "WabeCount");
            // 定义引用参数
            var refWabeCountArg = new CodeArgumentReferenceExpression("wabeCount");
            // 定义赋值语句
            var assignWabeCount = new CodeAssignStatement(refWabeCountProp, refWabeCountArg);

            jubjubCtor.Statements.Add(assignWabeCount);  // 附加赋值语句到构造函数

            jubjubClass.Members.Add(jubjubCtor);    // 附加构造函数到类

            // 定义成员属性
            CodeMemberProperty wabeCountProp = new CodeMemberProperty()
            {
                Attributes = MemberAttributes.Public | MemberAttributes.Final, // Final == Nonvirtual
                Type = new CodeTypeReference(typeof(int)),
                Name = "WabeCount"
            };
            // 为属性添加 get 语句
            wabeCountProp.GetStatements.Add(new CodeMethodReturnStatement(refWabeCountFld));

            // 为属性添加 set 语句
            var suppliedPropertyValue = new CodePropertySetValueReferenceExpression();  // value
            var zero = new CodePrimitiveExpression(0);
            var suppliedPropValIsLessThanZero = new CodeBinaryOperatorExpression(suppliedPropertyValue, CodeBinaryOperatorType.LessThan, zero);

            // if/else 语句进行赋值判断, CodeDOM 不支持三元运算表达式 (value < 0) ? 0 : value;
            var testSuppliedPropValAndAssign = new CodeConditionStatement(suppliedPropValIsLessThanZero,
                new CodeStatement[]
                {
                    new CodeAssignStatement(refWabeCountFld,zero)
                },
                new CodeStatement[]
                {
                    new CodeAssignStatement(refWabeCountFld,suppliedPropertyValue)
                });
            wabeCountProp.SetStatements.Add(testSuppliedPropValAndAssign);
            wabeCountProp.SetStatements.Add(new CodeMethodInvokeExpression(new CodeMethodReferenceExpression(refUpdatesFld, "Add"), refWabeCountFld));

            jubjubClass.Members.Add(wabeCountProp);  // 附加属性到类


            // 定义一个方法
            CodeMemberMethod methGetWabeCountHistory = new CodeMemberMethod
            {
                Attributes = MemberAttributes.Public | MemberAttributes.Final,
                Name = "GetWabeCountHistory",
                ReturnType = new CodeTypeReference(typeof(string))
            };

            jubjubClass.Members.Add(methGetWabeCountHistory);  // 附加方法到类

            // 定义本地变量并实例化
            methGetWabeCountHistory.Statements.Add(new CodeVariableDeclarationStatement("StringBuilder", "result"));
            var refResultVar = new CodeVariableReferenceExpression("result");
            methGetWabeCountHistory.Statements.Add(new CodeAssignStatement(refResultVar, new CodeObjectCreateExpression("StringBuilder")));

            // 定义本地变量 ndx
            methGetWabeCountHistory.Statements.Add(new CodeVariableDeclarationStatement(typeof(int), "ndx"));
            // 引用本地变量 ndx
            var refNdxVar = new CodeVariableReferenceExpression("ndx");

            #region  创建 for 语句

            // 赋值语句 ndx = 0
            var initNdxVar = new CodeAssignStatement(refNdxVar, new CodePrimitiveExpression(0));
            // 条件语句  ndx < this._updates.Count
            var testNdxWithUpdatesCount = new CodeBinaryOperatorExpression(refNdxVar, CodeBinaryOperatorType.LessThan,
                new CodePropertyReferenceExpression(refUpdatesFld, "Count"));
            // 自增语句
            var incrementNdxVar = new CodeAssignStatement(refNdxVar,
                new CodeBinaryOperatorExpression(refNdxVar, CodeBinaryOperatorType.Add,
                    new CodePrimitiveExpression(1)));
            // 比较 if(ndx == 0)
            var compareNdxWithZero = new CodeBinaryOperatorExpression(refNdxVar, CodeBinaryOperatorType.ValueEquality,
                new CodePrimitiveExpression(0));
            // 方法调用 result.AppendFormat("{0}", this._updates[ndx])
            var methAppendFormatInvoke = new CodeExpressionStatement(
                new CodeMethodInvokeExpression(
                    new CodeMethodReferenceExpression(refResultVar, "AppendFormat"),
                    new CodePrimitiveExpression("{0}"),
                    new CodeArrayIndexerExpression(refUpdatesFld, refNdxVar)
                    )
                  );
            // 方法调用 result.AppendFormat(", {0}", this._updates[ndx])
            var methAppendFormtInvokeWithCommas = new CodeExpressionStatement(
            new CodeMethodInvokeExpression(
                new CodeMethodReferenceExpression(refResultVar, "AppendFormat"),
                new CodePrimitiveExpression(", {0}"),
                new CodeArrayIndexerExpression(refUpdatesFld, refNdxVar)
                )
              );

            methGetWabeCountHistory.Statements.Add(
                new CodeIterationStatement(initNdxVar, testNdxWithUpdatesCount, incrementNdxVar,
                    new CodeConditionStatement(compareNdxWithZero,
                        new CodeStatement[] { methAppendFormatInvoke },
                        new CodeStatement[] { methAppendFormtInvokeWithCommas })));

            #endregion

            // 定义返回值
            methGetWabeCountHistory.Statements.Add(
                new CodeMethodReturnStatement(
                    new CodeMethodInvokeExpression(
                        new CodeMethodReferenceExpression(refResultVar, "ToString"))));

            return mimsyNamespace;
        }


        /// <summary>
        /// 编译到程序集
        /// Note: For you production applications, you should use 
        /// the CompileNamespaceToAssembly method as a starting point.
        /// </summary>
        /// <param name="ns">命名空间类型</param>
        /// <returns>最终程序集</returns>
        static Assembly CompileNamespaceToAssembly(CodeNamespace ns)
        {
            var ccu = new CodeCompileUnit();
            ccu.Namespaces.Add(ns);
            CompilerParameters cp = new CompilerParameters() { OutputAssembly = "dummy", GenerateInMemory = true };
            CompilerResults cr = CodeDomProvider.CreateProvider("C#").CompileAssemblyFromDom(cp, ccu);
            return cr.CompiledAssembly;
        }


        /// <summary>
        /// 从编译的程序集中创建动态类型
        /// </summary>
        /// <param name="asm">程序集</param>
        /// <param name="typeName">类型名称</param>
        /// <param name="ctorParams">实例化类型所需的参数</param>
        /// <returns>动态类型</returns>
        static dynamic InstantiateDynamicType(Assembly asm, string typeName, params object[] ctorParams)
        {
            Type targetType = asm.GetType(typeName);    // 获取类型
            return Activator.CreateInstance(targetType, ctorParams);  // 创建指定参数的类型实例
        }

        /// <summary>
        /// 生成代码
        /// </summary>
        /// <param name="ns">命名空间类型</param>
        /// <returns>最终代码</returns>
        static string GenerateCSharpCodeFromNamespace(CodeNamespace ns)
        {
            CodeGeneratorOptions genOpts = new CodeGeneratorOptions
            {
                BracingStyle = "C",
                IndentString = "    ",
                BlankLinesBetweenMembers = false
            };
            StringBuilder genedCode = new StringBuilder();
            using (StringWriter sw = new StringWriter(genedCode))
            {
                CodeDomProvider.CreateProvider("C#").GenerateCodeFromNamespace(ns, sw, genOpts);
            }
            return genedCode.ToString();
        }
    }
}
