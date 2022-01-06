import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            int n = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            int[][] arr = new int[2][n];
            for (int i = 0; i < n; i++) arr[0][i] = ((Integer.parseInt(st.nextToken()) + 1) / 2) * 2;
            int cnt = 0;
            int t = 0;
            while (true) {
                boolean chk = true;
                for (int i = 0; i < n - 1; i++) if (arr[t][i] != arr[t][i + 1]) chk = false;
                if (chk) break;
                for (int i = 0; i < n; i++) {
                    arr[(t + 1) % 2][i] = arr[t][i] / 2 + arr[t][(i + n - 1) % n] / 2;
                    arr[(t + 1) % 2][i] = ((arr[(t + 1) % 2][i] + 1) / 2) * 2;
                }
                t = (t + 1) % 2;
                cnt++;
            }
            sb.append(cnt + "\n");
        }
        System.out.println(sb);
    }
}
