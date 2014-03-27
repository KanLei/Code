using System;
using System.ComponentModel;
using System.Runtime.CompilerServices;

namespace NotifyChange
{
    public class Person : INotifyPropertyChanged
    {
        public Person() { }

        private string name;
        public string Name
        {
            get { return name; }
            set
            {
                name = value;
                NotifyChanged();
            }
        }

        private int age;
        public int Age
        {
            get { return age; }
            set
            {
                age = value;
                NotifyChanged();
            }
        }



        public event PropertyChangedEventHandler PropertyChanged;

        /// <summary>
        /// 使用 CallerMemberName 避免手动传入属性名称的麻烦
        /// </summary>
        /// <param name="propertyName"></param>
        public void NotifyChanged([CallerMemberName] string propertyName = "")
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Person p = new Person();

            p.PropertyChanged += ProcessPropertyChange; // 注册事件

            p.Name = "new name";    // 改变属性的值

            Console.Read();
        }

        static void ProcessPropertyChange(object sender, EventArgs e)
        {
            PropertyChangedEventArgs args = e as PropertyChangedEventArgs;

            Console.WriteLine("Type: {0}" + Environment.NewLine + "Changed: {1}",
                sender.GetType(), args.PropertyName);
        }
    }
}
