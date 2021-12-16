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
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) A[i] = Integer.parseInt(st.nextToken());
            Arrays.sort(A);
            st = new StringTokenizer(br.readLine());
            int[] B = new int[m];
            for (int i = 0; i < m; i++) B[i] = Integer.parseInt(st.nextToken());
            Arrays.sort(B);
            long sum = 0;
            int idx = 0;
            for (int i = 0; i < n; i++) {
                while (idx < m - 1) {
                    if (B[idx] >= A[i]) break;
                    idx++;
                }
                if (idx == 0) {
                    sum += B[0];
                } else {
                    if (Math.abs(B[idx - 1] - A[i]) <= Math.abs(B[idx] - A[i])) {
                        sum += B[idx - 1];
                    } else {
                        sum += B[idx];
                    }
                }
            }
            sb.append(sum + "\n");
        }
        System.out.println(sb);
    }
}
