import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int mi = 1;
        int mx = 10;
        while (true) {
            int n = Integer.parseInt(br.readLine());
            if (n == 0) break;
            String str = br.readLine();
            if (str.equals("too high")) {
                mx = Math.min(mx, n - 1);
            } else if (str.equals("too low")) {
                mi = Math.max(mi, n + 1);
            } else {
                if (mx >= n && n >= mi) {
                    sb.append("Stan may be honest\n");
                } else {
                    sb.append("Stan is dishonest\n");
                }
                mi = 1;
                mx = 10;
            }
        }
        System.out.println(sb);
    }
}
