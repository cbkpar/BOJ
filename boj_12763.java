import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int n, t, m;
    static ArrayList<line>[] arr;
    static int[] cost;
    static boolean[] chk;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        t = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        cost = new int[n + 1];
        chk = new boolean[n + 1];
        Arrays.fill(cost, 100000);
        int T = Integer.parseInt(br.readLine());
        arr = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) arr[i] = new ArrayList<line>();
        while (T-- > 0) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            int Time = Integer.parseInt(st.nextToken());
            int Cost = Integer.parseInt(st.nextToken());
            arr[s].add(new line(e, Time, Cost));
            arr[e].add(new line(s, Time, Cost));
        }
        chk[1] = true;
        dfs(1, 0, 0);
        System.out.println(cost[n] == 100000 ? "-1" : cost[n]);
    }

    private static void dfs(int pos, int T, int M) {
        cost[pos] = Math.min(cost[pos], M);
        for (line L : arr[pos]) {
            if (chk[L.e] || T + L.time > t || M + L.cost > m) continue;
            chk[L.e] = true;
            dfs(L.e, T + L.time, M + L.cost);
            chk[L.e] = false;
        }
    }
}

class line {
    int e;
    int time;
    int cost;

    public line(int e, int time, int cost) {
        this.e = e;
        this.time = time;
        this.cost = cost;
    }
}
