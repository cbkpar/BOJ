import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] month_arr = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        int[] month_day = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        StringTokenizer st = new StringTokenizer(br.readLine());
        String str = st.nextToken();
        int month = 0;
        for (int i = 0; i < 12; i++) {
            month++;
            if (str.equals(month_arr[i])) break;
        }
        str = st.nextToken();
        int day = (str.charAt(0) - '0') * 10 + str.charAt(1) - '0';
        int year = Integer.parseInt(st.nextToken());
        str = st.nextToken();
        int hour = (str.charAt(0) - '0') * 10 + str.charAt(1) - '0';
        int minute = (str.charAt(3) - '0') * 10 + str.charAt(4) - '0';
        boolean leap_year = false;
        if (year % 400 == 0) leap_year = true;
        if (year % 4 == 0 && year % 100 != 0) leap_year = true;
        if (leap_year) month_day[2]++;
        double time = -1;
        for (int i = 0; i < month; i++) time += month_day[i];
        time += day;
        time += (double) (hour * 60 + minute) / 1440;
        System.out.println(time * 100 / (365.0 + (leap_year ? 1 : 0)));
    }
}
