import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t, n, i;
        t = Integer.parseInt(br.readLine());
        for (i = 1; i <= t; i++) {
            n = Integer.parseInt(br.readLine());
            if (n == 0) {
                sb.append("Case #" + i + ": INSOMNIA\n");
            } else {
                sb.append("Case #" + i + ": " + brute(n) + "\n");
            }
        }
        System.out.println(sb);
    }

    public static int brute(int n) {
        int t = 0;
        int cnt = 0;
        boolean[] chk = new boolean[10];
        while (true) {
            t += n;
            cnt++;
            int k = t;
            while (k > 0) {
                chk[k % 10] = true;
                k /= 10;
            }
            boolean chkall = true;
            for (int i = 0; i < 10; i++) if (!chk[i]) chkall = false;
            if(!chkall) continue;
            break;
        }
        return t;
    }
}
