import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
        int D = Integer.parseInt(st.nextToken());

        boolean[] isprime = new boolean[B + 1];
        isprime[1] = true;
        for (int i = 2; i * i <= B; i++) {
            for (int j = i * i; j <= B; j += i) {
                isprime[j] = true;
            }
        }
        int cnt = 0;
        for (int i = A; i <= B; i++) {
            if (isprime[i]) continue;
            int tmp = i;
            boolean chk = false;
            while (tmp > 0) {
                if (tmp % 10 == D) chk = true;
                tmp /= 10;
            }
            if (chk) cnt++;
        }
        System.out.println(cnt);
    }
}
