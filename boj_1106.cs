using System;
using System.Linq;

class Program
{
  static void Main(String[] args)
  {
    String[] str = Console.ReadLine().Split();
    int c = int.Parse(str[0]);
    int n = int.Parse(str[1]);
    int[] dp = new int[c + 101];
    dp = dp.Select(i => 1000000000).ToArray();
    dp[0] = 0;
    while (n-- > 0)
    {
      str = Console.ReadLine().Split();
      int cost = int.Parse(str[0]);
      int cnt = int.Parse(str[1]);
      for (int i = cnt; i <= c + 100; i++) dp[i] = Math.Min(dp[i], dp[i - cnt] + cost);
    }
    int mi = int.MaxValue;
    for (int i = c; i <= c + 100; i++) mi = Math.Min(mi, dp[i]);
    Console.WriteLine(mi);
  }
}
