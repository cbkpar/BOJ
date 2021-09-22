import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, q, cnt, s, e, i;
        StringTokenizer st = new StringTokenizer(br.readLine());
        cnt = n = Integer.parseInt(st.nextToken());
        q = Integer.parseInt(st.nextToken());
        boolean[] chk = new boolean[n + 1];
        while (q-- > 0) {
            st = new StringTokenizer(br.readLine());
            s = Integer.parseInt(st.nextToken());
            e = Integer.parseInt(st.nextToken());
            for (i = s; i <= n; i += e) {
                if (!chk[i]) {
                    cnt--;
                    chk[i] = true;
                }
            }
        }
        System.out.println(cnt);
    }
}
