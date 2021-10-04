import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, k, b, i, mx;
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());
        int[] arr = new int[n + 1];
        while (b-- > 0) arr[Integer.parseInt(br.readLine())]++;
        for (i = 1; i <= n; i++) arr[i] += arr[i - 1];
        mx = Integer.MAX_VALUE;
        for (i = k; i <= n; i++) mx = Math.min(mx, arr[i] - arr[i - k]);
        System.out.println(mx);
    }
}
