import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int v, p;
    static long l, mi;
    static long[] arr;
    static long[] post;
    static long[] ans;
    static boolean[] chk;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        v = Integer.parseInt(st.nextToken());
        p = Integer.parseInt(st.nextToken());
        l = Long.parseLong(st.nextToken());
        mi = Long.MAX_VALUE;
        st = new StringTokenizer(br.readLine());
        arr = new long[v];
        chk = new boolean[v];
        for (int i = 0; i < v; i++) arr[i] = Long.parseLong(st.nextToken());
        post = new long[p];
        ans = new long[p];
        dfs(0, 0);
        sb.append(mi + "\n");
        for (int i = 0; i < p - 1; i++) sb.append(ans[i] + " ");
        sb.append(ans[p - 1]);
        System.out.println(sb);
    }

    private static void dfs(int t, int k) {
        if (k == p) {
            long sum = 0;
            for (int i = 0; i < v; i++) {
                if (chk[i]) continue;
                long tmp = Long.MAX_VALUE;
                for (int j = 0; j < p; j++) {
                    long diff = Math.abs(arr[i] - post[j]);
                    tmp = Math.min(tmp, Math.min(diff, l - diff));
                }
                sum += tmp;
                if (sum >= mi) return;
            }
            if (sum < mi) {
                mi = sum;
                ans = post.clone();
            }
            return;
        }
        for (int i = t; i < v; i++) {
            post[k] = arr[i];
            chk[i] = true;
            dfs(i + 1, k + 1);
            chk[i] = false;
        }
    }
}
