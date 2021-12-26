using System;
class Program
{
  static void Main(String[] args)
  {
    int[] arr = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
    int[] cnt = new int[100];
    for (int i = 0; i <= 99; i++)
    {
      cnt[i] = arr[i / 10] + arr[i % 10];
    }
    int n = int.Parse(Console.ReadLine());
    for (int i = 0; i <= 49; i++)
    {
      for (int j = i; i + j <= 99; j++)
      {
        int a = cnt[i];
        int b = cnt[j];
        int c = cnt[i + j];
        if (a + b + c + 4 == n)
        {
          Console.WriteLine(string.Format("{0:d2}+{1:d2}={2:d2}", i, j, (i + j)));
          return;
        }
      }
    }
    Console.WriteLine("impossible");
  }
}
