import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int cnt = 0;
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n + 1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) arr[i] += arr[i - 1] + Integer.parseInt(st.nextToken());
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                for (int k = i; k <= j; k++) {
                    if ((arr[k] - arr[k - 1]) * (j - i + 1) == (arr[j] - arr[i - 1])) {
                        cnt++;
                        break;
                    }
                }
            }
        }
        System.out.println(cnt);
    }
}
