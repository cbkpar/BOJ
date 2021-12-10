import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int h = Integer.parseInt(st.nextToken());
        int[] arr = new int[h + 1];
        for (int i = 0; i < n; i += 2) {
            int k = Integer.parseInt(br.readLine());
            arr[0]++;
            arr[k + 1]--;
            k = Integer.parseInt(br.readLine());
            arr[h - k + 1]++;
        }
        for (int i = 1; i <= h; i++) arr[i] += arr[i - 1];
        int mx = Integer.MAX_VALUE;
        int cnt = 0;
        for (int i = 1; i <= h; i++) {
            if (arr[i] < mx) {
                mx = arr[i];
                cnt = 1;
            } else if (arr[i] == mx) {
                cnt++;
            }
        }
        System.out.println(mx + " " + cnt);
    }
}
