import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        boolean[] chk = new boolean[1000001];
        chk[0] = chk[1] = true;
        for (int i = 2; i <= 1000; i++) {
            for (int j = i * i; j <= 1000000; j += i) {
                chk[j] = true;
            }
        }
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int cnt = 0;
            for (int i = 2; i * 2 <= n; i++) {
                if (!chk[i] && !chk[n - i]) cnt++;
            }
            sb.append(cnt + "\n");
        }
        System.out.println(sb);
    }
}
