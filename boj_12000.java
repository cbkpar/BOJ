import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(br.readLine());
        int presum = 0;
        for (int i = 0; i < n; i++) presum += arr[i];
        int now = 0;
        for (int i = 0; i < n; i++) now += arr[i] * i;
        int ans = now;
        for (int i = n - 1; i > 0; i--) {
            now += presum;
            now -= arr[i] * n;
            ans = Math.min(ans, now);
        }
        System.out.println(ans);
    }
}
