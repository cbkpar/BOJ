using System;
class Program
{
  static void Main(String[] args)
  {
    string[] str = Console.ReadLine().Split();
    int n = int.Parse(str[0]);
    int c = int.Parse(str[1]);
    int maxX = n;
    int maxY = n;
    while (c-- > 0)
    {
      str = Console.ReadLine().Split();
      int y = int.Parse(str[0]);
      int x = int.Parse(str[1]);
      if (x >= maxX || y >= maxY) continue;
      if (y * maxX >= x * maxY)
      {
        maxY = y;
      }
      else
      {
        maxX = x;
      }
    }
    Console.WriteLine(maxX * maxY);
  }
}
