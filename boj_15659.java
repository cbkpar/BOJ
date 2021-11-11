import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n, mx, mi;
    static int[] arr;
    static int[] op = new int[4];

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 4; i++) op[i] = Integer.parseInt(st.nextToken());
        mx = Integer.MIN_VALUE;
        mi = Integer.MAX_VALUE;
        btr(1, 0, arr[0]);
        System.out.println(mx + "\n" + mi);
    }

    private static void btr(int k, int sum, int tmp) {
        if (k == n) {
            mx = Math.max(mx, sum + tmp);
            mi = Math.min(mi, sum + tmp);
            return;
        }
        for (int i = 0; i < 4; i++) {
            if (op[i] > 0) {
                op[i]--;
                if (i == 0) {
                    btr(k + 1, sum + tmp, arr[k]);
                } else if (i == 1) {
                    btr(k + 1, sum + tmp, -arr[k]);
                } else if (i == 2) {
                    btr(k + 1, sum, tmp * arr[k]);
                } else if (i == 3) {
                    btr(k + 1, sum, tmp / arr[k]);
                }
                op[i]++;
            }
        }
    }
}
