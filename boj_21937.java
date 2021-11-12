import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    static ArrayList<Integer>[] route;
    static boolean[] chk;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        route = new ArrayList[n + 1];
        chk = new boolean[n + 1];
        for (int i = 1; i <= n; i++) route[i] = new ArrayList<>();
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            route[e].add(s);
        }
        System.out.println(dfs(Integer.parseInt(br.readLine())));
    }

    private static int dfs(int n) {
        int cnt = 0;
        chk[n] = true;
        for (int t : route[n]) {
            if (!chk[t]) cnt += dfs(t) + 1;
        }
        return cnt;
    }
}
