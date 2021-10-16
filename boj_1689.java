import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        ArrayList<node> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            arr.add(new node(s, e));
        }
        Collections.sort(arr, new Comparator<node>() {
            @Override
            public int compare(node o1, node o2) {
                if (o1.s != o2.s) return o1.s - o2.s;
                return o1.e - o2.e;
            }
        });
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int mx = 0;
        for (int i = 0; i < n; i++) {
            pq.add(arr.get(i).e);
            while (!pq.isEmpty()) {
                if (pq.peek() <= arr.get(i).s) {
                    pq.poll();
                } else {
                    break;
                }
            }
            mx = Math.max(mx, pq.size());
        }
        System.out.println(mx);
    }
}

class node {
    int s, e;

    public node(int s, int e) {
        this.s = s;
        this.e = e;
    }
}
