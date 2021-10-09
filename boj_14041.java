import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), ":");
        int t = Integer.parseInt(st.nextToken()) * 60 + Integer.parseInt(st.nextToken());
        int d = 240;
        while (true) {
            if (d <= 0) break;
            if (420 <= t && t < 600) {
                d -= 1;
            } else if (900 <= t && t < 1140) {
                d -= 1;
            } else {
                d -= 2;
            }
            t++;
        }
        t %= 1440;
        System.out.printf("%02d:%02d", t / 60, t % 60);
    }
}
