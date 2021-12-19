using System;
using System.Text;
class Program
{
  static void Main(String[] args)
  {
    StringBuilder sb = new StringBuilder();
    int z = int.Parse(Console.ReadLine());
    while (z-- > 0)
    {
      String[] str = Console.ReadLine().Split();
      int w = int.Parse(str[0]);
      int k = int.Parse(str[1]);
      sb.Append((w * k / 2) + "\n");

    }
    Console.WriteLine(sb);
  }
}
