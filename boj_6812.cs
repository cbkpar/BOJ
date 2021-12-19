using System;
using System.Text;
class Program
{
  static void Main(String[] args)
  {
    StringBuilder sb = new StringBuilder();
    int n = int.Parse(Console.ReadLine());
    int time = (n / 100) * 60 + n % 100;
    sb.Append(convert(time) + " in Ottawa\n");
    sb.Append(convert((time - 180)) + " in Victoria\n");
    sb.Append(convert((time - 120)) + " in Edmonton\n");
    sb.Append(convert((time - 60)) + " in Winnipeg\n");
    sb.Append(convert((time)) + " in Toronto\n");
    sb.Append(convert((time + 60)) + " in Halifax\n");
    sb.Append(convert((time + 90)) + " in St. John's\n");
    Console.WriteLine(sb);
  }
  private static int convert(int t)
  {
    t = (t + 1440) % 1440;
    return (t / 60) * 100 + t % 60;
  }
}
