using System;

namespace AbstractWithOverride
{
    public abstract class A
    {
        public virtual string Name{ get { return ""; } }
    }

    public abstract class B:A
    {
        // 强制 C 重新实现 Name，而不是使用 A 提供的默认实现
        public abstract override string Name{ get; }
    }

    public class C:B
    {
        public override string Name
        {
            get
            {
                throw new NotImplementedException();
            }
        }
    }

}

