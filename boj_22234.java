import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int T = Integer.parseInt(st.nextToken());
        int W = Integer.parseInt(st.nextToken());
        Queue<people> q = new LinkedList<>();
        while (N-- > 0) {
            st = new StringTokenizer(br.readLine());
            int p = Integer.parseInt(st.nextToken());
            int t = Integer.parseInt(st.nextToken());
            q.add(new people(p, t));
        }
        int M = Integer.parseInt(br.readLine());
        PriorityQueue<waiting> pq = new PriorityQueue<>(new Comparator<waiting>() {
            @Override
            public int compare(waiting o1, waiting o2) {
                return o1.c - o2.c;
            }
        });
        while (M-- > 0) {
            st = new StringTokenizer(br.readLine());
            int p = Integer.parseInt(st.nextToken());
            int t = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            pq.add(new waiting(p, t, c));
        }
        int rest = Math.min(T, q.peek().t);
        for (int i = 0; i < W; i++) {
            if (!pq.isEmpty()) {
                if (pq.peek().c - 1 == i) {
                    waiting w = pq.poll();
                    q.add(new people(w.p, w.t));
                }
            }
            sb.append(q.peek().p + "\n");
            if (--rest <= 0) {
                if (q.peek().t <= T) {
                    q.poll();
                } else {
                    people p = q.poll();
                    q.add(new people(p.p, p.t - T));
                }
                if (!q.isEmpty()) rest = Math.min(T, q.peek().t);
            }
        }
        System.out.println(sb);
    }
}

class people {
    int p;
    int t;

    public people(int p, int t) {
        this.p = p;
        this.t = t;
    }
}


class waiting {
    int p;
    int t;
    int c;

    public waiting(int p, int t, int c) {
        this.p = p;
        this.t = t;
        this.c = c;
    }
}
