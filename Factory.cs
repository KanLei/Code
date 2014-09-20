public class Factory
{
	public static T CreateInstance<T>() where T:new()
	{
		return new T();
	}

	// �вι��캯��
	public static T CreateInstance<T>(int num)
        {
            return (T)Activator.CreateInstance(typeof(T), num);
        }
}