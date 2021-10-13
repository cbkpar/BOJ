import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(arr);
        for (int i = 1; i < n; i++) arr[i] -= arr[0];
        int cnt = 1;
        int d = 0;
        while (d == 0) {
            d = arr[cnt++];
        }
        for (int i = cnt; i < n; i++) d = gcd(d, arr[i]);
        System.out.println(d);
    }

    private static int gcd(int a, int b) {
        if (b % a == 0) return a;
        return gcd(b % a, a);
    }
}
