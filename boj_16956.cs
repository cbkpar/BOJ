using System;
using System.Text;
class Program
{
  static void Main(String[] args)
  {
    StringBuilder sb = new StringBuilder();
    int[] dy = { -1, 0, 1, 0 };
    int[] dx = { 0, -1, 0, 1 };
    String[] split = Console.ReadLine().Split();
    int r = int.Parse(split[0]);
    int c = int.Parse(split[1]);
    char[,] map = new char[r, c];
    for (int i = 0; i < r; i++)
    {
      String str = Console.ReadLine();
      for (int j = 0; j < c; j++) map[i, j] = str[j];
    }
    for (int i = 0; i < r; i++)
    {
      for (int j = 0; j < c; j++)
      {
        if (map[i, j] == 'S')
        {
          for (int k = 0; k < 4; k++)
          {
            int ny = i + dy[k];
            int nx = j + dx[k];
            if (ny < 0 || ny > r - 1 || nx < 0 || nx > c - 1) continue;
            if (map[ny, nx] == 'W')
            {
              Console.WriteLine("0");
              return;
            }
            else if (map[ny, nx] == '.')
            {
              map[ny, nx] = 'D';
            }
          }
        }
      }
    }
    sb.Append("1\n");
    for (int i = 0; i < r; i++)
    {
      for (int j = 0; j < c; j++)
      {
        sb.Append(map[i, j]);
      }
      sb.Append("\n");
    }
    Console.WriteLine(sb);
  }
}
