import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n, m, i, tmx, mx;
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            if (n == 0 && m == 0) break;
            int[] arr = new int[10001];
            while (n-- > 0) {
                st = new StringTokenizer(br.readLine());
                for (i = 0; i < m; i++) arr[Integer.parseInt(st.nextToken())]++;
            }
            tmx = mx = 0;
            for (i = 1; i <= 10000; i++) tmx = Math.max(tmx, arr[i]);
            for (i = 1; i <= 10000; i++) if (arr[i] != tmx) mx = Math.max(mx, arr[i]);
            boolean chk = false;
            for (i = 1; i <= 10000; i++) {
                if (arr[i] == mx) {
                    if (chk) {
                        sb.append(" " + i);
                    } else {
                        sb.append(i);
                        chk = true;
                    }
                }
            }
            sb.append("\n");
        }
        System.out.println(sb);
    }
}
