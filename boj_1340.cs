using System;
class Program
{
  static void Main(String[] args)
  {
    String[] month_arr = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
    int[] month_day = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    string[] str = Console.ReadLine().Split();
    int month = 0;
    for (int i = 0; i < 12; i++) {
      month++;
      if (str[0].Equals(month_arr[i])) break;
    }
    int day = (str[1][0] - '0') * 10 + str[1][1] - '0';
    int year = int.Parse(str[2]);
    int hour = (str[3][0] - '0') * 10 + str[3][1] - '0';
    int minute = (str[3][3] - '0') * 10 + str[3][4] - '0';
    Boolean leap_year = false;
    if (year % 400 == 0) leap_year = true;
    if (year % 4 == 0 && year % 100 != 0) leap_year = true;
    if (leap_year) month_day[2]++;
    double time = -1;
    for (int i = 0; i < month; i++) time += month_day[i];
    time += day;
    time += (double)(hour * 60 + minute) / 1440;
    Console.WriteLine(time * 100 / (365.0 + (leap_year ? 1 : 0)));
  }
}
