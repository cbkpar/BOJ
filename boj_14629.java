import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static boolean[] chk = new boolean[10];
    static long diff = Long.MAX_VALUE;
    static long ans = Long.MAX_VALUE;
    static long num;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        num = Long.parseLong(br.readLine());
        for (int i = 1; i < 10; i++) {
            chk[i] = true;
            btr(i);
            chk[i] = false;
        }
        System.out.println(ans);
    }

    private static void btr(long sum) {
        if (Math.abs(num - sum) <= diff) {
            if (Math.abs(num - sum) != diff) {
                diff = Math.abs(num - sum);
                ans = sum;
            } else {
                ans = Math.min(ans, sum);
            }
        }
        for (int i = 0; i < 10; i++) {
            if (!chk[i]) {
                chk[i] = true;
                btr(sum * 10 + i);
                chk[i] = false;
            }
        }
    }
}
