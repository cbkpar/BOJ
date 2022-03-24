import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        boolean[] chk = new boolean[1000];
        while (n-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int num = Integer.parseInt(st.nextToken());
            int strike = Integer.parseInt(st.nextToken());
            int ball = Integer.parseInt(st.nextToken());
            for (int i = 1; i <= 9; i++) {
                for (int j = 1; j <= 9; j++) {
                    for (int k = 1; k <= 9; k++) {
                        if (i == j || j == k || k == i) continue;
                        int tmp = i * 100 + j * 10 + k;
                        if (chkstrike(num, tmp) != strike) chk[tmp] = true;
                        if (chkball(num, tmp) != ball) chk[tmp] = true;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                for (int k = 1; k <= 9; k++) {
                    if (i == j || j == k || k == i) continue;
                    if (!chk[i * 100 + j * 10 + k]) ans++;
                }
            }
        }
        System.out.println(ans);
    }

    private static int chkstrike(int num, int tmp) {
        int cnt = 0;
        for (int i = 0; i < 3; i++) {
            if (num % 10 == tmp % 10) cnt++;
            num /= 10;
            tmp /= 10;
        }
        return cnt;
    }

    private static int chkball(int num, int tmp) {
        int cnt = 0;
        if (num % 10 == tmp / 100 || num % 10 == (tmp % 100) / 10) cnt++;
        if ((num % 100) / 10 == tmp / 100 || (num % 100) / 10 == tmp % 10) cnt++;
        if (num / 100 == (tmp % 100) / 10 || num / 100 == tmp % 10) cnt++;
        return cnt;
    }
}
