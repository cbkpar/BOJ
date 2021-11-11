import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int l = Integer.parseInt(st.nextToken());
            int n = Integer.parseInt(st.nextToken());
            int mx = 0;
            int mi = 0;
            while (n-- > 0) {
                int k = Integer.parseInt(br.readLine());
                mx = Math.max(mx, Math.max(k, l - k));
                mi = Math.max(mi, Math.min(k, l - k));
            }
            sb.append(mi + " " + mx + "\n");
        }
        System.out.println(sb);
    }
}
