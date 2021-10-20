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
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int l = 0;
            int r = n - 1;
            boolean chk = false;
            while (l < r) {
                if (l == i) {
                    l++;
                    continue;
                }
                if (r == i) {
                    r--;
                    continue;
                }
                int tmp = arr[l] + arr[r];
                if (tmp == arr[i]) {
                    chk = true;
                    break;
                } else if (tmp > arr[i]) {
                    r--;
                } else {
                    l++;
                }
            }
            if (chk) cnt++;
        }
        System.out.println(cnt);
    }
}
