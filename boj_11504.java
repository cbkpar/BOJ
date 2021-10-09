import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int x = 0;
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < m; i++) {
                x *= 10;
                x += Integer.parseInt(st.nextToken());
            }
            int y = 0;
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < m; i++) {
                y *= 10;
                y += Integer.parseInt(st.nextToken());
            }
            int cnt = 0;
            int[] arr = new int[n];
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());
            int tmp = 0;
            int div = (int) Math.pow(10, m - 1);
            for (int i = 0; i < m; i++) {
                tmp *= 10;
                tmp += arr[i];
            }
            for (int i = 0; i < n; i++) {
                tmp %= div;
                tmp *= 10;
                tmp += arr[(i + m) % n];
                if (x <= tmp && tmp <= y) cnt++;
            }
            sb.append(cnt + "\n");
        }
        System.out.println(sb);
    }
}
