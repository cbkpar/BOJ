import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int s = Integer.parseInt(st.nextToken());
        PriorityQueue<test> pq = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            pq.add(new test(start, start + end));
        }
        int t = 0;
        while (!pq.isEmpty()) {
            if (t + m <= pq.peek().s) break;
            t = Math.max(t, pq.poll().e);
        }
        System.out.println(t + m <= s ? t : "-1");
    }
}

class test implements Comparable<test> {
    int s;
    int e;

    public test(int s, int e) {
        this.s = s;
        this.e = e;
    }

    @Override
    public int compareTo(test o) {
        return this.s - o.s;
    }
}
