using System;
using System.Text;
using System.Collections.Generic;
class Program
{
  static void Main(String[] args)
  {
    StringBuilder sb = new StringBuilder();

    Boolean[] isprime = new Boolean[1001];
    for (int i = 2; i * i <= 1000; i++)
    {
      for (int j = i * i; j <= 1000; j += i)
      {
        isprime[j] = true;
      }
    }
    List<int> prime = new List<int>();
    for (int i = 2; i < 1000; i++) if (!isprime[i]) prime.Add(i);
    int[,] ans = new int[1001, 3];
    int sz = prime.Count;
    for (int i = 0; i < sz; i++)
    {
      for (int j = i; j < sz; j++)
      {
        for (int k = j; k < sz; k++)
        {
          int sum = prime[i] + prime[j] + prime[k];
          if (sum >= 1000) continue;
          ans[sum, 0] = prime[i];
          ans[sum, 1] = prime[j];
          ans[sum, 2] = prime[k];
        }
      }
    }
    int t = int.Parse(Console.ReadLine());
    while (t-- > 0)
    {
      int k = int.Parse(Console.ReadLine());
      if (ans[k, 0] == 0)
      {
        sb.Append("0\n");
      }
      else
      {
        sb.Append(ans[k, 0] + " " + ans[k, 1] + " " + ans[k, 2] + "\n");
      }
    }
    Console.WriteLine(sb);
  }
}
