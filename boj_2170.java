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
        int n = Integer.parseInt(br.readLine());
        ArrayList<line> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            arr.add(new line(s, e));
        }
        Collections.sort(arr, new Comparator<line>() {
            @Override
            public int compare(line o1, line o2) {
                if (o1.s == o2.s) return o1.e - o2.e;
                return o1.s - o2.s;
            }
        });
        int ans = arr.get(0).e - arr.get(0).s;
        int s = arr.get(0).e;
        for (int i = 1; i < n; i++) {
            if (s <= arr.get(i).e) {
                if (arr.get(i).s <= s) {
                    ans += arr.get(i).e - s;
                    s = arr.get(i).e;
                } else {
                    ans += arr.get(i).e - arr.get(i).s;
                    s = arr.get(i).e;
                }
            }
        }
        System.out.println(ans);
    }
}

class line {
    int s, e;

    public line(int s, int e) {
        this.s = s;
        this.e = e;
    }
}
