/*
 * 实现一个与 ExpandoObject 功能相同的类，
 * 可以动态的添加和移除属性
 */

using System;
using System.Collections.Generic;
using System.Dynamic;


namespace ImplementMyExpandoObject
{
    class Program
    {
        static void Main(string[] args)
        {
            dynamic vessel = new MyExpandoObject();
            vessel.Name = "Little";
            vessel.Age = 12;
            vessel.keelLengthInFeet = 32;
            vessel.Longitude = 37.55f;
            vessel.Latitude = -76.34f;
            Console.WriteLine("The {0} year old vessel " +
                "name {1} has a keel length of {2} feet " +
                "and is currently located at {3} / {4}.",
                vessel.AGE, vessel.name, vessel.keelLengthINfeet,
                vessel.Longitude, vessel.Latitude);

            Console.Read();
        }
    }

    class MyExpandoObject : DynamicObject
    {
        private Dictionary<string, object> _dict = new Dictionary<string, object>();

        public override bool TryGetMember(GetMemberBinder binder, out object result)
        {
            result = null;
            if (_dict.ContainsKey(binder.Name.ToUpper()))
            {
                result = _dict[binder.Name.ToUpper()];
                return true;
            }
            return false;
        }

        public override bool TrySetMember(SetMemberBinder binder, object value)
        {
            if (_dict.ContainsKey(binder.Name.ToUpper()))
            {
                _dict[binder.Name.ToUpper()] = value;
            }
            else
            {
                _dict.Add(binder.Name.ToUpper(), value);
            }
            return true;
        }
    }
}
