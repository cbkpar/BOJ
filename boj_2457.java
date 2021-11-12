import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        PriorityQueue<flower> pq = new PriorityQueue<>();
        while (n-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken()) * 100;
            s += Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken()) * 100;
            e += Integer.parseInt(st.nextToken());
            if (s == e) continue;
            if (s > e) {
                int t = s;
                s = e;
                e = t;
            }
            e--;
            if (s < 301) s = 301;
            if (e > 1130) e = 1130;
            pq.add(new flower(s, e));
        }
        int cnt = 0;
        int start = 300;
        while (!pq.isEmpty()) {
            if (pq.peek().s > start + 1) break;
            cnt++;
            int end = start;
            while (!pq.isEmpty()) {
                if (pq.peek().s > start + 1) break;
                end = Math.max(end, pq.poll().e);
            }
            if (end == 1130) {
                System.out.println(cnt);
                return;
            }
            start = end;
        }
        System.out.println("0");
    }
}

class flower implements Comparable<flower> {
    int s;
    int e;

    public flower(int s, int e) {
        this.s = s;
        this.e = e;
    }

    @Override
    public int compareTo(flower o) {
        return this.s - o.s;
    }
}
