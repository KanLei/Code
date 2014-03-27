// 1.第一种方式
public sealed class Singleton
{
    // 静态在变量或属性被第一次访问之前执行，在静态构造函数执行之前执行
    // 可能会到导致提前运行，由于BeforeFieldInit
    private  static readonly Singleton singleton=new Singleton();

    public static Singleton TheSingleton
    {
        get { return singleton; }
    }

    private Singleton() { }
}

// 2.第二种方式
public sealed class Singleton
{
    // 静态构造函数在变量或属性被第一次访问之前执行
    private static readonly Singleton singleton;

    // 显示地告诉编译器不被标记为BeforeFieldInit
    static Singleton()
    {
        singleton = new Singleton();
    }

    public static Singleton TheSingleton
    {
        get { return singleton; }
    }

    private Singleton() { }
}
