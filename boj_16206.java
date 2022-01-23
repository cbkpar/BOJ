import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(arr);
        int rest = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] < 10) continue;
            if (arr[i] % 10 == 0) {
                if (arr[i] / 10 - 1 <= m) {
                    m -= arr[i] / 10 - 1;
                    cnt += arr[i] / 10;
                } else {
                    rest += arr[i] / 10;
                }
            } else {
                rest += arr[i] / 10;
            }
        }
        System.out.println(cnt + Math.min(m, rest));
    }
}
