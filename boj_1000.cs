using System;
class Program
{
  static void Main(String[] args)
  {
    string[] input = Console.ReadLine().Split();
    Console.WriteLine(int.Parse(input[0]) + int.Parse(input[1]));
  }
}
