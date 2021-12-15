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
            int n = Integer.parseInt(br.readLine());
            long[] arr = new long[n];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) arr[i] = Long.parseLong(st.nextToken());
            long sum = 0;
            long mx = arr[n - 1];
            for (int i = n - 2; i >= 0; i--) {
                if (arr[i] > mx) {
                    mx = arr[i];
                } else if (arr[i] < mx) {
                    sum += mx - arr[i];
                }
            }
            sb.append(sum + "\n");
        }
        System.out.println(sb);
    }
}
