import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, k, i, mi;
        n = Integer.parseInt(br.readLine());
        boolean[] origin = new boolean[n + 1];
        boolean[] ans = new boolean[n + 1];
        String a = br.readLine();
        String b = br.readLine();
        for (i = 0; i < n; i++) if (a.charAt(i) == '1') origin[i] = true;
        for (i = 0; i < n; i++) if (b.charAt(i) == '1') ans[i] = true;
        mi = Integer.MAX_VALUE;
        boolean[] chk = origin.clone();
        k = 1;
        chk[0] = !chk[0];
        chk[1] = !chk[1];
        for (i = 1; i < n; i++) {
            if (chk[i - 1] != ans[i - 1]) {
                k++;
                chk[i] = !chk[i];
                chk[i + 1] = !chk[i + 1];
            }
        }
        if (chk[n - 1] == ans[n - 1]) mi = Math.min(mi, k);
        chk = origin.clone();
        k = 0;
        for (i = 1; i < n; i++) {
            if (chk[i - 1] != ans[i - 1]) {
                k++;
                chk[i] = !chk[i];
                chk[i + 1] = !chk[i + 1];
            }
        }
        if (chk[n - 1] == ans[n - 1]) mi = Math.min(mi, k);
        System.out.println(mi == Integer.MAX_VALUE ? "-1" : mi);
    }
}
