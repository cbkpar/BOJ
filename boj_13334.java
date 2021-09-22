import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static StringBuilder sb = new StringBuilder();

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, d, i, s, e,mx;
        n = Integer.parseInt(br.readLine());
        ArrayList<road> arr = new ArrayList<>();
        for (i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            s = Integer.parseInt(st.nextToken());
            e = Integer.parseInt(st.nextToken());
            if (s < e) {
                arr.add(new road(s, e));
            } else {
                arr.add(new road(e, s));
            }
        }
        d = Integer.parseInt(br.readLine());
        Collections.sort(arr, new Comparator<road>() {
            @Override
            public int compare(road o1, road o2) {
                if (o1.e != o2.e) {
                    return o1.e - o2.e;
                } else {
                    return o1.s - o2.s;
                }
            }
        });
        mx = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (i = 0; i < n; i++) {
            e = arr.get(i).e;
            if(e-arr.get(i).s<=d) pq.add(arr.get(i).s);
            while(!pq.isEmpty()){
                if(e-pq.peek()<=d) break;
                pq.poll();
            }
            mx = Math.max(mx,pq.size());
        }
        System.out.println(mx);
    }
}

class road {
    int s, e;

    public road(int s, int e) {
        this.s = s;
        this.e = e;
    }
}
