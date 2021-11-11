import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        int w = Integer.parseInt(st.nextToken());
        int h = Integer.parseInt(st.nextToken());
        ArrayList<Integer>[] arr = new ArrayList[m];
        for (int i = 0; i < m; i++) arr[i] = new ArrayList<>();
        int[] cnt = new int[m];
        st = new StringTokenizer(br.readLine());
        PriorityQueue<people> pq = new PriorityQueue<>();
        for (int i = 0; i < m; i++) {
            cnt[i] = Integer.parseInt(st.nextToken()) / w;
            pq.add(new people(i, 0));
        }
        int[] d = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) d[i] = Integer.parseInt(st.nextToken());
        PriorityQueue<people2> ready = new PriorityQueue<>();
        for (int i = 0; i <= n - w; i++) {
            while (!pq.isEmpty()) {
                if (pq.peek().time > i) break;
                int t = pq.poll().num;
                ready.add(new people2(t, cnt[t]));
            }
            int mx = Math.min(d[i], ready.size());
            for (int j = 0; j < mx; j++) {
                int t = ready.poll().num;
                arr[t].add(i);
                if (--cnt[t] > 0) pq.add(new people(t, i + w + h));
            }
            for (int j = i; j < i + w; j++) d[j] -= mx;
        }
        for (int i = 0; i < n; i++) {
            if (d[i] > 0) {
                System.out.println("-1");
                return;
            }
        }
        sb.append("1\n");
        for (int i = 0; i < m; i++) {
            sb.append((arr[i].get(0) + 1));
            for (int j = 1; j < arr[i].size(); j++) sb.append(" " + (arr[i].get(j) + 1));
            sb.append("\n");
        }
        System.out.println(sb);
    }
}

class people implements Comparable<people> {
    int num;
    int time;

    public people(int num, int time) {
        this.num = num;
        this.time = time;
    }

    @Override
    public int compareTo(people o) {
        return this.time - o.time;
    }
}

class people2 implements Comparable<people2> {
    int num;
    int rest;

    public people2(int num, int rest) {
        this.num = num;
        this.rest = rest;
    }

    @Override
    public int compareTo(people2 o) {
        return o.rest - this.rest;
    }
}
