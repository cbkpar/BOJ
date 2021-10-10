import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int start = 1440;
        int end = 0;
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), ":");
            int time = Integer.parseInt(st.nextToken()) * 60 + Integer.parseInt(st.nextToken());
            if (time < 390 || time > 1140) continue;
            start = Math.min(start, time);
            end = Math.max(end, time);
        }
        if (start >= 390 && start <= 600 && end >= 390 && end <= 960) {
            System.out.println("24000");
        } else if (start >= 390 && start <= 600 && end >= 961 && end <= 1140) {
            System.out.println("36000");
        } else if (start >= 601 && start <= 960 && end >= 601 && end <= 960) {
            System.out.println("16800");
        } else if (start >= 601 && start <= 1140 && end >= 961 && end <= 1140) {
            System.out.println("24000");
        } else {
            System.out.println("0");
        }
    }
}
