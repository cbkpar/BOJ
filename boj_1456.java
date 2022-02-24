import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        boolean[] isprime = new boolean[10000001];
        for (int i = 2; i * i <= 10000000; i++) {
            for (int j = i * i; j <= 10000000; j += i) isprime[j] = true;
        }
        StringTokenizer st = new StringTokenizer(br.readLine());
        long a = Long.parseLong(st.nextToken());
        long b = Long.parseLong(st.nextToken());
        int cnt = 0;
        for (int i = 2; i <= 10000000; i++) {
            if (isprime[i]) continue;
            long t = i;
            while (true) {
                if (t >= Long.MAX_VALUE / i) break;
                t = t * i;
                if (t > b) break;
                if (a <= t && t <= b) cnt++;
            }
        }
        System.out.println(cnt);
    }
}
