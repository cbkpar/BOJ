import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static ArrayList<node>[] arr;
    static int n, start, end;
    static int[] dist;
    static boolean[][] visited;
    static ArrayList<Integer>[] road;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            if (n == 0 && m == 0) break;
            st = new StringTokenizer(br.readLine());
            start = Integer.parseInt(st.nextToken());
            end = Integer.parseInt(st.nextToken());
            arr = new ArrayList[n];
            for (int i = 0; i < n; i++) arr[i] = new ArrayList<node>();
            while (m-- > 0) {
                st = new StringTokenizer(br.readLine());
                int s = Integer.parseInt(st.nextToken());
                int e = Integer.parseInt(st.nextToken());
                int w = Integer.parseInt(st.nextToken());
                arr[s].add(new node(e, w));
            }
            road = new ArrayList[n];
            for (int i = 0; i < n; i++) road[i] = new ArrayList<>();
            visited = new boolean[n][n];
            dijkstra(start);
            bfs(end);
            dijkstra(start);
            sb.append((dist[end]==1000000000?"-1":dist[end])+"\n");
        }
        System.out.println(sb);
    }

    private static void dijkstra(int s) {
        dist = new int[n];
        Arrays.fill(dist, 1000000000);

        PriorityQueue<node> pq = new PriorityQueue<>();
        dist[start] = 0;
        pq.add(new node(start, 0));
        while (!pq.isEmpty()) {
            node p = pq.poll();
            for (node N : arr[p.e]) {
                if (visited[p.e][N.e]) continue;
                if (dist[N.e] > dist[p.e] + N.w) {
                    dist[N.e] = dist[p.e] + N.w;
                    road[N.e].clear();
                    road[N.e].add(p.e);
                    pq.add(new node(N.e, dist[N.e]));
                } else if (dist[N.e] == dist[p.e] + N.w) {
                    road[N.e].add(p.e);
                }
            }

        }
    }

    private static void bfs(int s) {
        Queue<Integer> q = new LinkedList<>();
        q.add(s);
        while (!q.isEmpty()) {
            int p = q.poll();
            for(int t : road[p]){
                if(!visited[t][p]){
                    visited[t][p] = true;
                    q.add(t);
                }
            }
        }
    }
}

class node implements Comparable<node> {
    int e;
    int w;

    public node(int e, int w) {
        this.e = e;
        this.w = w;
    }

    @Override
    public int compareTo(node o) {
        return Integer.compare(this.w, o.w);
    }
}
