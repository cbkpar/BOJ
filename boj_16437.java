import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    static long[] cnt;
    static ArrayList<Integer>[] route;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        cnt = new long[n + 1];
        route = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) route[i] = new ArrayList<>();
        for (int i = 2; i <= n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            if (st.nextToken().charAt(0) == 'S') {
                cnt[i] += Integer.parseInt(st.nextToken());
            } else {
                cnt[i] -= Integer.parseInt(st.nextToken());
            }
            route[Integer.parseInt(st.nextToken())].add(i);
        }
        System.out.println(dfs(1));
    }

    private static long dfs(int n) {
        long tmp = cnt[n];
        for (int t : route[n]) tmp += dfs(t);
        return tmp >= 0 ? tmp : 0;
    }
}
