import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    static int[] visited;
    static int[] scc;
    static int dcnt, scnt;
    static Stack<Integer> stack = new Stack<>();
    static ArrayList<Integer>[] node;
    static boolean[] chk;
    static int[] cnt;
    static int[] sum;
    static HashSet<Integer>[] link;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int V = Integer.parseInt(st.nextToken());
        int E = Integer.parseInt(st.nextToken());
        visited = new int[V + 1];
        scc = new int[V + 1];
        node = new ArrayList[V + 1];
        for (int i = 1; i <= V; i++) node[i] = new ArrayList<>();
        while (E-- > 0) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            node[e].add(s);
        }
        for (int i = 1; i <= V; i++) if (visited[i] == 0) dfs(i);
        link = new HashSet[scnt + 1];
        cnt = new int[scnt + 1];
        sum = new int[scnt + 1];
        for (int i = 1; i <= scnt; i++) link[i] = new HashSet<>();
        for (int i = 1; i <= V; i++) {
            int s = scc[i];
            cnt[s]++;
            for (int e : node[i]) {
                if (link[s].contains(scc[e]) || s == scc[e]) continue;
                link[s].add(scc[e]);
            }
        }
        for (int i = 1; i <= scnt; i++) {
            chk = new boolean[scnt + 1];
            sum[i] = sumdfs(i);
        }
        int mx = 0;
        for (int i = 1; i <= V; i++) mx = Math.max(mx, sum[scc[i]]);
        for (int i = 1; i <= V; i++) if (mx == sum[scc[i]]) sb.append(i + " ");
        System.out.println(sb);
    }

    private static int dfs(int s) {
        int ret = visited[s] = ++dcnt;
        stack.add(s);
        for (int e : node[s]) {
            if (visited[e] == 0) {
                ret = Math.min(ret, dfs(e));
            } else if (scc[e] == 0) {
                ret = Math.min(ret, visited[e]);
            }
        }
        if (ret == visited[s]) {
            ++scnt;
            while (true) {
                int e = stack.pop();
                scc[e] = scnt;
                if (s == e) break;
            }
        }
        return ret;
    }

    private static int sumdfs(int s) {
        chk[s] = true;
        int ret = cnt[s];
        for (int e : link[s]) {
            if (chk[e]) continue;
            chk[e] = true;
            ret += sumdfs(e);
        }
        return ret;
    }
}
