import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n;
    static int[] arr;
    static int mx = 0;
    static boolean[] chk;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new int[n];
        chk = new boolean[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());
        btr(0, 0);
        System.out.println(mx);
    }

    private static void btr(int k, int sum) {
        if (k == n - 2) {
            mx = Math.max(mx, sum);
            return;
        }
        for (int i = 1; i < n - 1; i++) {
            if (!chk[i]) {
                chk[i] = true;
                int left = i - 1;
                while (chk[left]) left--;
                int right = i + 1;
                while (chk[right]) right++;
                btr(k + 1, sum + arr[left] * arr[right]);
                chk[i] = false;
            }
        }
    }
}
