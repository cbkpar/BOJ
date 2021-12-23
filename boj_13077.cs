using System;
using System.Text;
using System.Collections.Generic;
class Program
{
  static void Main(String[] args)
  {
    StringBuilder sb = new StringBuilder();
    int t = int.Parse(Console.ReadLine());
    while (t-- > 0)
    {
      String[] str = Console.ReadLine().Split('/');
      int p = int.Parse(str[0]);
      int q = int.Parse(str[1]);
      int idx = 1;
      Stack<int> stack = new Stack<int>();
      while (true)
      {
        if (p == 1 && q == 1) break;
        if (p > q)
        {
          stack.Push(1);
          p -= q;

        }
        else
        {
          stack.Push(0);
          q -= p;
        }
      }
      while (stack.Count != 0)
      {
        if (stack.Pop() == 0)
        {
          idx = idx * 2;
        }
        else
        {
          idx = idx * 2 + 1;
        }
      }
      sb.Append(idx + "\n");
    }
    Console.WriteLine(sb);
  }
}
