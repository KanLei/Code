// 1.第一种方式
public class Singleton
{
    // 静态在变量或属性被第一次访问之前执行，在静态构造函数执行之前执行
    private static readonly Singleton singleton=new Singleton();

    public static Singleton TheSingleton
    {
        get { return singleton; }
    }

    private Singleton() { }
}

// 2.第二种方式
public class Singleton
{
    // 静态构造函数在变量或属性被第一次访问之前执行
    private static readonly Singleton singleton;

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
