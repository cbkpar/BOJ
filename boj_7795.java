import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
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
            int[] A = new int[n];
            int[] B = new int[m + 1];
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) A[i] = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < m; i++) B[i] = Integer.parseInt(st.nextToken());
            B[m] = Integer.MAX_VALUE;
            Arrays.sort(A);
            Arrays.sort(B);
            int cnt = 0;
            int tmp = 0;
            for (int i = 0; i < n; i++) {
                while (B[tmp] < A[i]) tmp++;
                cnt += tmp;
            }
            sb.append(cnt + "\n");
        }
        System.out.println(sb);
    }
}
