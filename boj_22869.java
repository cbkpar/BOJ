import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        boolean[] chk = new boolean[n];
        chk[0] = true;
        int[] arr = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n - 1; i++) {
            if (!chk[i]) continue;
            for (int j = i + 1; j < n; j++) {
                if (k >= (j - i) * (1 + Math.abs(arr[i] - arr[j]))) {
                    chk[j] = true;
                }
            }
        }
        System.out.println(chk[n - 1] ? "YES" : "NO");
    }
}
