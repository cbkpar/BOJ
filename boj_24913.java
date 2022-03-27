import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int Q = Integer.parseInt(st.nextToken());
        long mx = 0;
        long sum = 0;
        long[] candidate = new long[N + 2];
        while (Q-- > 0) {
            st = new StringTokenizer(br.readLine());
            int choice = Integer.parseInt(st.nextToken());
            if (choice == 1) {
                int x = Integer.parseInt(st.nextToken());
                int p = Integer.parseInt(st.nextToken());
                candidate[p] += x;
                if (p == N + 1) continue;
                sum += x;
                mx = Math.max(mx, candidate[p]);
            } else {
                long x = Integer.parseInt(st.nextToken());
                long y = Integer.parseInt(st.nextToken());
                boolean iswin = true;
                if (mx >= candidate[N + 1] + x) iswin = false;
                if ((sum + y) / N + ((sum + y) % N != 0 ? 1 : 0) >= candidate[N + 1] + x) iswin = false;
                sb.append(iswin ? "YES\n" : "NO\n");
            }
        }
        System.out.println(sb);
    }
}
