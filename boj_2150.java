import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    static int[] visited;
    static int[] scc;
    static int dcnt, scnt;
    static ArrayList<Integer>[] node;
    static ArrayList<Integer>[] group;
    static Stack<Integer> stack = new Stack<>();
    static StringBuilder sb = new StringBuilder();

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
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
            node[s].add(e);
        }
        for (int i = 1; i <= V; i++) if (visited[i] == 0) dfs(i);
        int tcnt = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        group = new ArrayList[scnt];
        for (int i = 0; i < scnt; i++) group[i] = new ArrayList<>();
        for (int i = 1; i <= V; i++) {
            if (map.containsKey(scc[i])) {
                group[map.get(scc[i])].add(i);
            } else {
                map.put(scc[i], tcnt++);
                group[map.get(scc[i])].add(i);
            }
        }
        for (int i = 0; i < scnt; i++) {
            if (!group[i].isEmpty()) {
                for (int n : group[i]) sb.append(n + " ");
                sb.append("-1\n");
            }
        }
        System.out.println(scnt + "\n" + sb);
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
}
