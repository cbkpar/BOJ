import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int c, t, i, s, e, k;
        StringTokenizer st = new StringTokenizer(br.readLine());
        c = Integer.parseInt(st.nextToken());
        int[] ch = new int[c];
        for (i = 0; i < c; i++) ch[i] = Integer.parseInt(br.readLine());
        Arrays.sort(ch);
        t = Integer.parseInt(st.nextToken());
        ArrayList<cow> arr = new ArrayList<>();
        for (i = 0; i < t; i++) {
            st = new StringTokenizer(br.readLine());
            s = Integer.parseInt(st.nextToken());
            e = Integer.parseInt(st.nextToken());
            arr.add(new cow(s, e));
            Collections.sort(arr, new Comparator<cow>() {
                @Override
                public int compare(cow o1, cow o2) {
                    if (o1.s != o2.s) return o1.s - o2.s;
                    return o1.e - o2.e;
                }
            });
        }
        k = s = 0;
        PriorityQueue<Integer> q = new PriorityQueue<>();
        for (i = 0; i < c; i++) {
            while (s < t && arr.get(s).s <= ch[i]) {
                q.add(arr.get(s).e);
                s++;
            }
            while (!q.isEmpty()) {
                if (q.peek() < ch[i]) {
                    q.poll();
                } else {
                    break;
                }
            }
            if (!q.isEmpty()) {
                q.poll();
                k++;
            }
        }
        System.out.println(k);
    }
}

class cow {
    int s;
    int e;

    public cow(int s, int e) {
        this.s = s;
        this.e = e;
    }
}
