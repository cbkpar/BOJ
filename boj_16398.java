import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {

    static int[] par;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] map = new int[n][n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) map[i][j] = Integer.parseInt(st.nextToken());
        }
        ArrayList<node> Node = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                Node.add(new node(i, j, map[i][j]));
            }
        }
        Collections.sort(Node, new Comparator<node>() {
            @Override
            public int compare(node o1, node o2) {
                return o1.w - o2.w;
            }
        });
        par = new int[n];
        for (int i = 0; i < n; i++) par[i] = i;
        int cnt = 0;
        long cost = 0;
        for (node N : Node) {
            if (cnt == n - 1) break;
            int x = find(N.s);
            int y = find(N.e);
            if (x != y) {
                union(N.s, N.e);
                cost += N.w;
                cnt++;
            }
        }
        System.out.println(cost);

    }

    private static int find(int x) {
        if (x == par[x]) return par[x];
        return par[x] = find(par[x]);
    }

    private static void union(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            par[x] = y;
        }
    }
}

class node {
    int s, e, w;

    public node(int s, int e, int w) {
        this.s = s;
        this.e = e;
        this.w = w;
    }
}
