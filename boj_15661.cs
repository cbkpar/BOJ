using System;
class Program
{
  static int cnt;
  static int[,] score;
  static Boolean[] team;
  static int mi = int.MaxValue;
  
  static void Main(String[] args)
  {
    cnt = int.Parse(Console.ReadLine());
    score = new int[cnt, cnt];
    for (int i = 0; i < cnt; i++)
    {
      string[] str = Console.ReadLine().Split();
      for (int j = 0; j < cnt; j++) score[i, j] = int.Parse(str[j]);
    }
    team = new Boolean[cnt];
    dfs(0);
    Console.WriteLine(mi);
  }

  private static void dfs(int n)
  {
    if (n == cnt)
    {
      mi = Math.Min(mi, calc());
      return;
    }
    team[n] = true;
    dfs(n + 1);
    team[n] = false;
    dfs(n + 1);
  }

  private static int calc()
  {
    int tscore = 0;
    for (int i = 0; i < cnt; i++)
    {
      for (int j = 0; j < cnt; j++)
      {
        if (i == j) continue;
        if (team[i] == team[j])
        {
          tscore += team[i] ? score[i, j] : -score[i, j];
        }
      }
    }
    return Math.Abs(tscore);
  }
}
