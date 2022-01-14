import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] A = new int[n];
        int[] B = new int[m];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) A[i] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++) B[i] = Integer.parseInt(st.nextToken());
        int mx = 1;
        int now = 1;
        Arrays.sort(A);
        Arrays.sort(B);
        n--;
        m--;
        while (true) {
            if (now == 0 || n < 0 || m < 0) break;
            now--;
            while (A[n]-- > 0) {
                now += B[m--];
                if (m < 0) break;
            }
            n--;
            mx = Math.max(mx, now);
        }
        System.out.println(mx);
    }
}
