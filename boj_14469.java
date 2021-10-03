import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, i, t, c;
        n = Integer.parseInt(br.readLine());
        ArrayList<cow> arr = new ArrayList<>();
        for (i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            t = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());
            arr.add(new cow(t, c));
            Collections.sort(arr, new Comparator<cow>() {
                @Override
                public int compare(cow o1, cow o2) {
                    return o1.time - o2.time;
                }
            });
        }
        t = 0;
        for (i = 0; i < n; i++) {
            if (t <= arr.get(i).time) {
                t = arr.get(i).time + arr.get(i).cost;
            } else {
                t += arr.get(i).cost;
            }
        }
        System.out.println(t);
    }
}

class cow {
    int time;
    int cost;

    public cow(int time, int cost) {
        this.time = time;
        this.cost = cost;
    }
}
