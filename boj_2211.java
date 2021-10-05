import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static ArrayList<node>[] arr;
    static int n, cnt;
    static StringBuilder sb = new StringBuilder();
    static int[] dist;
    static HashSet<String> set = new HashSet<>();

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        arr = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) arr[i] = new ArrayList<node>();
        int k = Integer.parseInt(st.nextToken());
        while (k-- > 0) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            arr[s].add(new node(e, w));
            arr[e].add(new node(s, w));
        }
        cnt = 0;
        dijkstra(1);
        System.out.println(cnt + "\n" + sb);
    }

    private static void dijkstra(int s) {
        dist = new int[n + 1];
        Arrays.fill(dist, 1000000000);
        int[] road = new int[n + 1];
        boolean[] chk = new boolean[n + 1];
        PriorityQueue<node> pq = new PriorityQueue<>();
        pq.add(new node(1, 0));
        dist[s] = 0;
        while (!pq.isEmpty()) {
            node p = pq.poll();
            chk[p.e] = true;
            for (node N : arr[p.e]) {
                if (dist[N.e] > dist[p.e] + N.w) {
                    dist[N.e] = dist[p.e] + N.w;
                    road[N.e] = p.e;
                    pq.add(new node(N.e, dist[N.e]));
                }
            }
        }

        for (int i = 2; i <= n; i++) {
            int e = i;
            while (road[e] != 0) {
                if (!set.contains(e + " " + road[e])) {
                    cnt++;
                    set.add(e + " " + road[e]);
                    sb.append(e + " " + road[e] + "\n");
                }
                e = road[e];
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
