import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int[] cnt = new int[10002];
        boolean[] chk = new boolean[10002];
        while (n-- > 0) {
            int num = Integer.parseInt(br.readLine()) + 1;
            cnt[num]++;
            chk[num] = true;
        }
        int ans = 0;
        for (int i = 1; i <= 10001; i++) cnt[i] += cnt[i - 1];
        for (int i = 1; i <= 10001; i++) {
            if (!chk[i]) continue;
            ans = Math.max(ans, cnt[Math.min(i + k, 10001)] - cnt[i - 1]);
        }
        System.out.println(ans);
    }
}
