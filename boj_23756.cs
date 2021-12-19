using System;
class Program
{
  static void Main(String[] args)
  {
    int n = int.Parse(Console.ReadLine());
    int prev = int.Parse(Console.ReadLine());
    int sum = 0;
    while (n-- > 0)
    {
      int next = int.Parse(Console.ReadLine());
      int tmp = Math.Abs(next - prev);
      if (tmp > 180) tmp = 360 - tmp;
      sum += tmp;
      prev = next;
    }
    Console.WriteLine(sum);
  }
}
