import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int pine = 0;
        int blue = 0;
        int[] time = new int[9];
        Arrays.fill(time, -11);
        while (n-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int t = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            if (a <= 4) {
                if (time[a] + 10 >= t) pine += 50;
                pine += 100;
            } else {
                if (time[a] + 10 >= t) blue += 50;
                blue += 100;
            }
            time[a] = t;
        }
        System.out.println(pine + " " + blue);
    }
}
