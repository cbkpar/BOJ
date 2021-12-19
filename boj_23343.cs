using System;
class Program
{
  static void Main(String[] args)
  {
    int x = 0;
    int y = 0;
    String[] str = Console.ReadLine().Split();
    try
    {
      x = int.Parse(str[0]);
    }
    catch (FormatException e)
    {
      Console.WriteLine("NaN");
      return;
    }
    try
    {
      y = int.Parse(str[1]);
    }
    catch (FormatException e)
    {
      Console.WriteLine("NaN");
      return;
    }
    Console.WriteLine(x - y);
  }
}
