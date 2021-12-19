using System;
using System.Text;
using System.Collections.Generic;
class Program
{
  static void Main(String[] args)
  {
    StringBuilder sb = new StringBuilder();
    String A = Console.ReadLine();
    String B = Console.ReadLine();
    int n = A.Length;
    int m = B.Length;
    int[,] dp = new int[n + 1, m + 1];
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= m; j++)
      {
        if (A[i - 1] == B[j - 1])
        {
          dp[i, j] = dp[i - 1, j - 1] + 1;
        }
        else
        {
          dp[i, j] = Math.Max(dp[i - 1, j], dp[i, j - 1]);
        }
      }
    }
    int t = dp[n, m];
    int y = n;
    int x = m;
    Stack<Char> stack = new Stack<Char>();
    while (t > 0)
    {
      while (true)
      {
        if (dp[y, x - 1] != t) break;
        x--;
      }
      while (true)
      {
        if (dp[y - 1, x] != t) break;
        y--;
      }
      stack.Push(A[y - 1]);
      x--;
      y--;
      t--;
    }
    while (stack.Count != 0) sb.Append(stack.Pop());
    Console.WriteLine(sb);
  }
}
