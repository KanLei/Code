using System;
using System.IO;
using System.Text;
using System.CodeDom;
using System.CodeDom.Compiler;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Collections.Generic;
using System.Collections.ObjectModel;

namespace KanLei.GenerateEntity
{
    class GenerateEntity
    {
        static void Main(string[] args)
        {
            foreach (CompilerInfo ci in CodeDomProvider.GetAllCompilerInfo())
            {
                foreach (string language in ci.GetLanguages())
                {
                    Console.Write("{0}\t", language);
                }
                Console.WriteLine();
            }
            Console.WriteLine();

            var connStr = new SqlConnectionStringBuilder();
            connStr.DataSource = "LEI";
            connStr.InitialCatalog = "DB_HotelManager";
            connStr.IntegratedSecurity = true;
            GenerateCode(connStr.ConnectionString);
        }


        /// <summary>
        /// 生成代码
        /// </summary>
        /// <param name="connStr"></param>
        private static void GenerateCode(string connStr)
        {
            var dt = QueryDatabase(connStr);

            // 根据表名进行分组
            var query = from row in dt.AsEnumerable()
                        group row by row.Field<string>("TABLE_NAME");

            foreach (var group in query)
            {
                CodeNamespace ns = new CodeNamespace("HotelManager_0254");
                ns.Imports.Add(new CodeNamespaceImport("System"));

                CodeTypeDeclaration type = new CodeTypeDeclaration(group.Key);
                type.Attributes = MemberAttributes.Public;
                ns.Types.Add(type);

                // 添加表中字段
                foreach (var item in group)
                {
                    var propertyName = item.Field<string>("COLUMN_NAME");
                    var propertyType = MapDataTypeToDatabase(item.Field<string>("DATA_TYPE"));
                    var fieldName = propertyName.Substring(0, 1).ToLower() + propertyName.Remove(0, 1);

                    var field = new CodeMemberField(propertyType, fieldName);
                    var property = new CodeMemberProperty
                    {
                        Name = propertyName,
                        Attributes = MemberAttributes.Public | MemberAttributes.Final,
                        Type = propertyType
                    };
                    property.GetStatements.Add(new CodeMethodReturnStatement(new CodeFieldReferenceExpression(new CodeThisReferenceExpression(), fieldName)));
                    property.SetStatements.Add(new CodeAssignStatement(new CodeFieldReferenceExpression(new CodeThisReferenceExpression(), fieldName), new CodePropertySetValueReferenceExpression()));

                    type.Members.Add(field);
                    type.Members.Add(property);
                }

                // 生成 cs 代码
                GenerateCodeCS(ns, group.Key);
            }
        }


        /// <summary>
        /// 根据数据库中数据类型获取 c# 中相对应的数据类型
        /// </summary>
        /// <param name="key">数据库中字符的类型</param>
        /// <returns>CodeTypeReference</returns>
        public static CodeTypeReference MapDataTypeToDatabase(string key)
        {
            var types = new Dictionary<string, CodeTypeReference>();
            types.Add("int", new CodeTypeReference(typeof(System.Int32)));
            types.Add("varchar", new CodeTypeReference(typeof(System.String)));
            types.Add("nvarchar", new CodeTypeReference(typeof(System.String)));
            types.Add("image", new CodeTypeReference(typeof(System.String)));
            types.Add("text", new CodeTypeReference(typeof(System.String)));

            types.Add("money", new CodeTypeReference(typeof(System.Decimal)));
            types.Add("datetime", new CodeTypeReference(typeof(System.DateTime)));
            types.Add("float", new CodeTypeReference(typeof(System.Double)));

            // 只读字典
            var dicts = new ReadOnlyDictionary<string, CodeTypeReference>(types);
            return dicts[key];
        }


        /// <summary>
        /// 生成 c# 代码
        /// </summary>
        /// <param name="ns"></param>
        /// <param name="tableName"></param>
        private static void GenerateCodeCS(CodeNamespace ns, string tableName)
        {
            var compilerOptions = new CodeGeneratorOptions()
            {
                IndentString = "    ",
                BracingStyle = "C",
                BlankLinesBetweenMembers = false
            };

            var codeText = new StringBuilder();
            using (var codeWriter = new StringWriter(codeText))
            {
                CodeDomProvider.CreateProvider("c#").GenerateCodeFromNamespace(ns, codeWriter, compilerOptions);
            }
            var script = codeText.ToString();
            Console.WriteLine(script);

            using (TextWriter txt = File.CreateText(string.Format("{0}.cs", tableName)))
            {
                txt.Write(codeText);
            }
        }


        /// <summary>
        /// 查询数据库
        /// </summary>
        /// <returns>返回由表名、属性名、属性类型等构成的表结构</returns>
        private static DataTable QueryDatabase(string connStr)
        {
            var dt = new DataTable();

            using (var conn = new SqlConnection(connStr))
            {
                conn.Open();
                //string cmdText = string.Format("select name from syscolumns where id=object_id('{0}')", "Admin_Info");
                string cmdText = string.Format("select * from information_schema.columns");
                using (var adapter = new SqlDataAdapter(cmdText, conn))
                {
                    adapter.Fill(dt);
                }
            }
            return dt;
        }
    }

}
