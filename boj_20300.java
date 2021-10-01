import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, i;
        long ans = 0;
        n = Integer.parseInt(br.readLine());
        long[] arr = new long[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (i = 0; i < n; i++) arr[i] = Long.parseLong(st.nextToken());
        Arrays.sort(arr);
        if (n % 2 == 0) {
            for (i = 0; i < n; i++) ans = Math.max(ans, arr[i] + arr[n - i - 1]);
        } else {
            ans = arr[n - 1];
            for (i = 0; i < n - 1; i++) ans = Math.max(ans, arr[i] + arr[n - i - 2]);
        }
        System.out.println(ans);
    }
}
