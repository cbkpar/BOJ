using System;
class Program
{
  static void Main(String[] args)
  {
    string str = Console.ReadLine();
    int k = 0;
    int p = 0;
    int mx = 0;
    int sz = str.Length;
    for (int i = 0; i < sz; i++)
    {
      if (str[i] == 'K')
      {
        if (k != 0) k--;
        p++;
      }
      else
      {
        if (p != 0) p--;
        k++;
      }
      mx = Math.Max(mx, k + p);
    }
    Console.WriteLine(mx);
  }
}
