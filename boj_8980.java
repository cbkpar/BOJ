import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[] sum = new int[n + 1];
        int c = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(br.readLine());
        int ans = 0;
        ArrayList<route> arr = new ArrayList<>();
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            int amount = Integer.parseInt(st.nextToken());
            arr.add(new route(s, e, amount));
        }
        Collections.sort(arr, new Comparator<route>() {
            @Override
            public int compare(route o1, route o2) {
                if (o1.e != o2.e) return o1.e - o2.e;
                return o2.s - o1.s;
            }
        });
        for (route r : arr) {
            int mx = r.amount;
            for (int i = r.s; i < r.e; i++) mx = Math.min(mx, c - sum[i]);
            for (int i = r.s; i < r.e; i++) sum[i] += mx;
            ans += mx;
        }
        System.out.println(ans);
    }
}

class route {
    int s;
    int e;
    int amount;

    public route(int s, int e, int amount) {
        this.s = s;
        this.e = e;
        this.amount = amount;
    }
}
