import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int[] arr = new int[1000001];
        int n, i, sq, mi;
        for (i = 1; i <= 1000000; i++) {
            sq = (int) Math.sqrt(i);
            arr[i] = i - sq * (sq - 1);
        }
        while (true) {
            mi = n = Integer.parseInt(br.readLine());
            if (n == 0) break;
            for (i = 0; i * i * i <= n; i++) {
                mi = Math.min(mi, i + arr[n - i * i * i]);
            }
            sb.append(mi + "\n");
        }
        System.out.println(sb);
    }
}
