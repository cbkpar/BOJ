import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, i, j, mx, t;
        n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        for (i = 0; i < n; i++) arr[i] = Integer.parseInt(br.readLine());
        Arrays.sort(arr);
        mx = 4;
        for (i = 0; i < n; i++) {
            t = 4;
            for (j = i + 1; j < n && j <= i + 4; j++) {
                if (arr[j] - arr[i] <= 4) t--;
            }
            mx = Math.min(mx, t);

        }
        System.out.println(mx);
    }
}
