import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        long[] arr = new long[n + 1];
        for (int i = 1; i <= n; i++) arr[i] = Long.parseLong(br.readLine());
        Arrays.sort(arr);
        for (int i = n - 1; i >= 0; i--) {
            if (m > (n - i) * (arr[i + 1] - arr[i])) {
                m -= (n - i) * (arr[i + 1] - arr[i]);
            } else {
                for (int j = n; j > i; j--) {
                    arr[j] = arr[i + 1] - m / (n - i);
                }
                m %= (n - i);
                for (int j = 0; j < m; j++) arr[i + 1 + j]--;
                break;
            }
        }
        BigInteger big = new BigInteger("0");
        for (int i = 1; i <= n; i++) big = big.add(new BigInteger(Long.toString(arr[i] * arr[i])));
        System.out.println(big.remainder(new BigInteger("18446744073709551616")));
    }
}
