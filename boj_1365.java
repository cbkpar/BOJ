import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, i, l, r, m, t;
        n = Integer.parseInt(br.readLine());
        ArrayList<Integer> arr = new ArrayList<>();
        arr.add(-1);
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (i = 0; i < n; i++) {
            t = Integer.parseInt(st.nextToken());
            if (arr.get(arr.size() - 1) < t) {
                arr.add(t);
            } else {
                l = 0;
                r = arr.size() - 1;
                while (l < r) {
                    m = (l + r) / 2;
                    if (arr.get(m) < t) {
                        l = m + 1;
                    } else {
                        r = m;
                    }
                }
                arr.set(l, t);
            }
        }
        System.out.println(n-arr.size()+1);
    }
}
