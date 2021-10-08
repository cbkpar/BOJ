import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static ArrayList<link>[] link;
    static int[] dist;


    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            link = new ArrayList[n + 1];
            dist = new int[n + 1];
            Arrays.fill(dist, 1000000000);
            for (int i = 1; i <= n; i++) link[i] = new ArrayList<link>();
            while (d-- > 0) {
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                int s = Integer.parseInt(st.nextToken());
                link[b].add(new link(a, s));
            }
            dijkstra(c);
            int ans = 0;
            int mx = 0;
            for (int i = 1; i <= n; i++) {
                if (dist[i] != 1000000000) {
                    ans++;
                    mx = Math.max(mx, dist[i]);
                }
            }
            sb.append(ans + " " + mx + "\n");
        }
        System.out.println(sb);
    }

    private static void dijkstra(int c) {
        dist[c] = 0;
        PriorityQueue<link> pq = new PriorityQueue<>();
        pq.add(new link(c, 0));
        while (!pq.isEmpty()) {
            link S = pq.poll();
            for (link E : link[S.e]) {
                if (dist[E.e] > dist[S.e] + E.t) {
                    dist[E.e] = dist[S.e] + E.t;
                    pq.add(new link(E.e, dist[E.e]));
                }
            }
        }

    }
}

class link implements Comparable<link> {
    int e;
    int t;

    public link(int e, int t) {
        this.e = e;
        this.t = t;
    }

    @Override
    public int compareTo(link o) {
        return Integer.compare(this.t, o.t);
    }
}
