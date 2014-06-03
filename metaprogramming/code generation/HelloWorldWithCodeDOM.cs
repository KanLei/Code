using System;
using System.Text;

using System.CodeDom.Compiler;
using System.CodeDom;
using System.IO;


namespace HelloWorld
{
    class Program
    {
        static void Main(string[] args)
        {
            // 输出所有支持生成代码的语言
            foreach (CompilerInfo ci in CodeDomProvider.GetAllCompilerInfo())
            {
                foreach (var language in ci.GetLanguages())
                {
                    Console.Write("{0}    ", language);
                }
                Console.WriteLine();
            }

            CodeNamespace prgNamespace = BuildProgram();
            var compilerOptions = new CodeGeneratorOptions()
            {
                IndentString = "  ",
                BracingStyle = "C",  // 花括号的风格
                BlankLinesBetweenMembers = false
            };
            var codeText = new StringBuilder();
            using (var codeWriter = new StringWriter(codeText))
            {
                CodeDomProvider.CreateProvider("c#").GenerateCodeFromNamespace(
                    prgNamespace, codeWriter, compilerOptions);
            }
            var script = codeText.ToString();
            Console.WriteLine(script);


            Console.Read();
        }

        // 生成 Hello World 源代码
        static CodeNamespace BuildProgram()
        {
            var ns = new CodeNamespace("MetaWorld");
            var systemImport = new CodeNamespaceImport("System");
            ns.Imports.Add(systemImport);
            var programClass = new CodeTypeDeclaration("Program");
            ns.Types.Add(programClass);
            var methodMain = new CodeMemberMethod
            {
                Attributes = MemberAttributes.Static,
                Name = "Main"
            };
            methodMain.Statements.Add(new CodeMethodInvokeExpression(
                new CodeSnippetExpression("Console"), "WriteLine",
                new CodePrimitiveExpression("Hello World!")));
            programClass.Members.Add(methodMain);
            return ns;
        }
    }
}
