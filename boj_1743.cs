using System;
using System.Collections.Generic;
class Program
{
  static void Main(String[] args)
  {
    int[] dy = { -1, 0, 1, 0 };
    int[] dx = { 0, -1, 0, 1 };
    String[] str = Console.ReadLine().Split();
    int n = int.Parse(str[0]);
    int m = int.Parse(str[1]);
    int k = int.Parse(str[2]);
    Boolean[,] isfood = new Boolean[n, m];
    while (k-- > 0)
    {
      str = Console.ReadLine().Split();
      int r = int.Parse(str[0]) - 1;
      int c = int.Parse(str[1]) - 1;
      isfood[r, c] = true;
    }
    Boolean[,] visited = new Boolean[n, m];
    int mx = 0;
    Queue<pos> q = new Queue<pos>();
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (isfood[i, j] && !visited[i, j])
        {
          q.Enqueue(new pos(i, j));
          int cnt = 1;
          visited[i, j] = true;
          while (q.Count > 0)
          {
            pos p = q.Dequeue();
            for (int t = 0; t < 4; t++)
            {
              int ty = p.y + dy[t];
              int tx = p.x + dx[t];
              if (ty < 0 || ty > n - 1 || tx < 0 || tx > m - 1) continue;
              if (visited[ty, tx]) continue;
              visited[ty, tx] = true;
              if (isfood[ty, tx])
              {
                cnt++;
                q.Enqueue(new pos(ty, tx));
              }
            }
          }
          mx = Math.Max(mx, cnt);

        }
      }
    }
    Console.WriteLine(mx);
  }
}

public class pos
{
  public int y;
  public int x;

  public pos(int y, int x)
  {
    this.y = y;
    this.x = x;
  }
}
