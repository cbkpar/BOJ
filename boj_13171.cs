using System;
class Program
{
  static void Main(String[] args)
  {
    const long MOD = 1000000007;
    long A = long.Parse(Console.ReadLine()) % MOD;
    long X = long.Parse(Console.ReadLine());
    long ans = 1;
    while (X > 0)
    {
      if (X % 2 == 1) ans = (ans * A) % MOD;
      X >>= 1;
      A = (A * A) % MOD;
    }
    Console.WriteLine(ans);
  }
}
