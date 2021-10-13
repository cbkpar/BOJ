import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = i;
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken()) - 1;
            int e = Integer.parseInt(st.nextToken()) - 1;
            for (int i = s; i < e; i++) {
                if (i >= e - i + s) break;
                int tmp = arr[i];
                arr[i] = arr[e - i + s];
                arr[e - i + s] = tmp;
            }
        }
        int[][] par = new int[2][n];
        int tmp = 0;
        for (int i = 0; i < n; i++) par[0][i] = arr[i];
        k--;
        while (k > 0) {
            if (k % 2 == 1) {
                for (int i = 0; i < n; i++) arr[i] = par[tmp][arr[i]];
            }
            for (int i = 0; i < n; i++) par[(tmp + 1) % 2][i] = par[tmp][par[tmp][i]];
            k /= 2;
            tmp = (tmp + 1) % 2;
        }
        for (int i = 0; i < n; i++) sb.append((arr[i] + 1) + "\n");
        System.out.println(sb);
    }
}
