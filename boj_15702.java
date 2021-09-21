import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n, m, tn, ts, num, s, i;
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        ts = 0;
        tn = Integer.MAX_VALUE;
        int[] arr = new int[n];
        st = new StringTokenizer(br.readLine());
        for (i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            num = Integer.parseInt(st.nextToken());
            s = 0;
            for (i = 0; i < n; i++) {
                if (st.nextToken().charAt(0) == 'O') s += arr[i];
            }
            if (s > ts) {
                ts = s;
                tn = num;
            } else if (s == ts) {
                tn = Math.min(tn, num);
            }
        }
        System.out.println(tn + " " + ts);
    }
}
