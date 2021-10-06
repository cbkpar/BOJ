import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    static ArrayList<Integer>[] arr;
    static int n;
    static int[][] par;
    static int[] depth;
    static boolean[] chk;


    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        n = Integer.parseInt(br.readLine());
        arr = new ArrayList[n + 1];
        par = new int[n + 1][21];
        depth = new int[n + 1];
        chk = new boolean[n + 1];
        for (int i = 1; i <= n; i++) arr[i] = new ArrayList<Integer>();
        for (int i = 0; i < n - 1; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            arr[s].add(e);
            arr[e].add(s);
        }
        dfs(1, 0);
        dpar();
        int m = Integer.parseInt(br.readLine());
        while (m-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            sb.append(lca(s, e) + "\n");
        }
        System.out.println(sb);

    }

    private static void dfs(int n, int d) {
        chk[n] = true;
        depth[n] = d;
        for (int e : arr[n]) {
            if (!chk[e]) {
                par[e][0] = n;
                dfs(e, d + 1);
            }
        }
    }

    private static void dpar() {
        for (int i = 1; i < 21; i++) {
            for (int j = 1; j <= n; j++) {
                par[j][i] = par[par[j][i - 1]][i - 1];
            }
        }
    }

    private static int lca(int x, int y) {
        if (depth[x] > depth[y]) {
            int t = x;
            x = y;
            y = t;
        }
        for (int i = 20; i >= 0; i--) if (depth[y] - depth[x] >= (1 << i)) y = par[y][i];
        if (x == y) return x;
        for (int i = 20; i >= 0; i--) {
            if (par[x][i] != par[y][i]) {
                x = par[x][i];
                y = par[y][i];
            }
        }
        return par[x][0];
    }
}
