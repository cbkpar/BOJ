import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int mx = 0;
        int cnt = 1;
        long ans = 0;
        long tmp = 1;
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            int t = Integer.parseInt(st.nextToken());
            if (t > mx) {
                ans = (ans + tmp * cnt) % 1000000007;
                tmp = ans;
                cnt = 1;
                mx = t;
            } else {
                cnt++;
            }
        }
        System.out.println(ans);
    }
}
