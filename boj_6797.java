import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            if (n == 0) break;
            if (n == 1) {
                sb.append("0\n");
                continue;
            }
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());
            int[] diff = new int[n];
            for (int i = 0; i < n - 1; i++) diff[i] = arr[i + 1] - arr[i];
            for (int i = 1; i < n; i++) {
                boolean chk = true;
                for (int j = i; j < n - 1; j++) {
                    if (diff[j] != diff[j - i]) chk = false;
                }
                if (chk) {
                    sb.append(i + "\n");
                    break;
                }
            }
        }
        System.out.println(sb);
    }
}
