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
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        ArrayList<work> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int time = Integer.parseInt(st.nextToken());
            int limit = Integer.parseInt(st.nextToken());
            arr.add(new work(time, limit));
        }
        Collections.sort(arr, new Comparator<work>() {
            @Override
            public int compare(work o1, work o2) {
                return o1.limit - o2.limit;
            }
        });
        int min = 0;
        int ans = Integer.MAX_VALUE;
        for (work W : arr) {
            min += W.time;
            if (min > W.limit) {
                System.out.println("-1");
                return;
            }
            ans = Math.min(ans, W.limit - min);
        }
        System.out.println(ans);
    }
}

class work {
    int time;
    int limit;

    public work(int time, int limit) {
        this.time = time;
        this.limit = limit;
    }

}
