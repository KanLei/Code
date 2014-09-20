public class Factory
{
	public static T CreateInstance<T>() where T:new()
	{
		return new T();
	}

	// 有参构造函数
	public static T CreateInstance<T>(int num)
        {
            return (T)Activator.CreateInstance(typeof(T), num);
        }
}