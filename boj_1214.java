import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int d = Integer.parseInt(st.nextToken());
        int p = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());
        if (p < q) {
            int tmp = p;
            p = q;
            q = tmp;
        }
        int k = d / p + (d % p != 0 ? 1 : 0);
        int mi = k * p;
        HashSet<Integer> set = new HashSet<>();
        set.add(mi);
        for (int i = k - 1; i >= 0; i--) {
            int tmp_d = d - p * i;
            int tmp = tmp_d / q + (tmp_d % q != 0 ? 1 : 0);
            tmp_d = p * i + tmp * q;
            if (set.contains(tmp_d)) break;
            set.add(tmp_d);
            mi = Math.min(mi, tmp_d);
        }
        System.out.println(mi);
    }
}
