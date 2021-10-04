import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, i, mx;
        n = Integer.parseInt(br.readLine());
        int[] arr = new int[n * 2];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (i = 0; i < 2 * n; i++) arr[i] = Integer.parseInt(st.nextToken());
        mx = Integer.MAX_VALUE;
        Arrays.sort(arr);
        for (i = 0; i < n; i++) {
            mx = Math.min(mx, arr[i] + arr[2 * n - i - 1]);
        }
        System.out.println(mx);
    }
}
