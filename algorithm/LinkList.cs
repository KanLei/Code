using System;

public class Node
{
    public Node m_next;
    public string value;

    public Node(string name)
    {
        this.value = name;
    }
}

public sealed class LinkedList
{
    public Node m_head;

    public LinkedList Add(Node newNode)
    {
        // 头插法
        newNode.m_next = m_head;
        m_head = newNode;
        return this;
    }
}

public class Program
{
    public static void Main()
    {
        var linkList = new LinkedList();
        //linkList.Add(new Node("Node1"));
        //linkList.Add(new Node("Node2"));
        //linkList.Add(new Node("Node3"));
        //linkList.Add(new Node("Node4"));

        linkList.Add(new Node("Apple")).Add(new Node("Orange")).
            Add(new Node("Banana")).Add(new Node("Pear"));

        var temp = linkList.m_head;
        while (temp != null)
        {
            Console.WriteLine(temp.value);
            temp = temp.m_next;
        }
    }
}