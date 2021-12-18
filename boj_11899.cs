using System;
using System.Collections.Generic;
class Program 
{
  static void Main(String[] args)
  {
    string str = Console.ReadLine();
    Stack<char> stack = new Stack<char>();
    int sz = str.Length;
    for (int i = 0; i < sz; i++)
    {
      if (stack.Count == 0)
      {
        stack.Push(str[i]);
      }
      else
      {
        if (stack.Peek() == '(' && str[i] == ')')
        {
          stack.Pop();
        }
        else
        {
          stack.Push(str[i]);
        }
      }
    }
    Console.WriteLine(stack.Count);
  }
}
