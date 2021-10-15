import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] arr = new int[n + 1];
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            int t = Integer.parseInt(st.nextToken());
            int i = Integer.parseInt(st.nextToken());
            if (t == 1) {
                int x = Integer.parseInt(st.nextToken());
                arr[i] = arr[i] | 1 << (x - 1);
            } else if (t == 2) {
                int x = Integer.parseInt(st.nextToken());
                arr[i] -= arr[i] & 1 << (x - 1);
            } else if (t == 3) {
                arr[i] = (arr[i] << 1) % (1 << 20);
            } else {
                arr[i] = arr[i] >> 1;
            }
        }
        HashSet<Integer> set = new HashSet<>();
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (set.contains(arr[i])) continue;
            set.add(arr[i]);
            cnt++;
        }
        System.out.println(cnt);
    }
}
