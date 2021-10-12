import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        ArrayList<lecture> lec = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            lec.add(new lecture(s, e));
        }
        Collections.sort(lec, new Comparator<lecture>() {
            @Override
            public int compare(lecture o1, lecture o2) {
                if (o1.s != o2.s) return o1.s - o2.s;
                return o1.e - o2.e;
            }
        });
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int mx = 0;
        for (int i = 0; i < n; i++) {
            pq.add(lec.get(i).e);
            while (!pq.isEmpty()) {
                if (pq.peek() > lec.get(i).s) {
                    break;
                } else {
                    pq.poll();
                }
            }
            mx = Math.max(mx, pq.size());

        }
        System.out.println(mx);
    }
}

class lecture {
    int s, e;

    public lecture(int s, int e) {
        this.s = s;
        this.e = e;
    }
}
