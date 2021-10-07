import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    static ArrayList<node>[] arr;
    static int n;
    static int[][] par;
    static int[] depth;
    static int[][] dist;
    static boolean[] chk;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        n = Integer.parseInt(br.readLine());
        arr = new ArrayList[n + 1];
        par = new int[n + 1][21];
        depth = new int[n + 1];
        dist = new int[n + 1][21];
        chk = new boolean[n + 1];
        int[] energy = new int[n + 1];
        for (int i = 1; i <= n; i++) arr[i] = new ArrayList<node>();
        for (int i = 1; i <= n; i++) energy[i] = Integer.parseInt(br.readLine());
        for (int i = 0; i < n - 1; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            arr[s].add(new node(e, d));
            arr[e].add(new node(s, d));
        }
        dfs(1, 0);
        dpar();
        for (int i = 1; i <= n; i++) sb.append(lca(i, energy[i]) + "\n");
        System.out.println(sb);
    }

    private static void dfs(int n, int d) {
        chk[n] = true;
        depth[n] = d;
        for (node N : arr[n]) {
            if (!chk[N.e]) {
                par[N.e][0] = n;
                dist[N.e][0] = N.dist;
                dfs(N.e, d + 1);
            }
        }
    }

    private static void dpar() {
        for (int i = 1; i < 21; i++) {
            for (int j = 1; j <= n; j++) {
                par[j][i] = par[par[j][i - 1]][i - 1];
                dist[j][i] = dist[j][i - 1] + dist[par[j][i - 1]][i - 1];
            }
        }
    }

    private static int lca(int num, int e) {
        for (int i = 20; i >= 0; i--) {
            if (e >= dist[num][i]) {
                e -= dist[num][i];
                num = par[num][i];
            }
        }
        return num == 0 ? 1 : num;
    }
}

class node {
    int e;
    int dist;

    public node(int e, int dist) {
        this.e = e;
        this.dist = dist;
    }
}
