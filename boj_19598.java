import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        ArrayList<conference> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            arr.add(new conference(s, e));
        }
        Collections.sort(arr, new Comparator<conference>() {
            @Override
            public int compare(conference o1, conference o2) {
                return o1.s - o2.s;
            }
        });
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int mx = 0;
        for (int i = 0; i < n; i++) {
            conference c = arr.get(i);
            pq.add(c.e);
            while (!pq.isEmpty()) {
                if (pq.peek() > c.s) break;
                pq.poll();
            }
            mx = Math.max(mx, pq.size());
        }
        System.out.println(mx);
    }
}

class conference {
    int s;
    int e;

    public conference(int s, int e) {
        this.s = s;
        this.e = e;
    }
}
