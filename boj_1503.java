import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int n;
    static int mx = Integer.MAX_VALUE;
    static HashSet<Integer> set = new HashSet<>();

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        if (m != 0) {
            st = new StringTokenizer(br.readLine());
            while (m-- > 0) set.add(Integer.parseInt(st.nextToken()));
        }
        dfs(1, 0, 1);
        System.out.println(mx);
    }

    private static void dfs(int t, int k, int s) {
        if (k == 3) {
            mx = Math.min(mx, Math.abs(n - s));
            return;
        }
        while (true) {
            if (set.contains(t)) {
                t++;
                continue;
            }
            dfs(t, k + 1, s * t);
            if (s * t >= n) break;
            t++;
        }
    }
}
