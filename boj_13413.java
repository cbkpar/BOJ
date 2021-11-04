import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int sz = Integer.parseInt(br.readLine());
            String A = br.readLine();
            String B = br.readLine();
            int w = 0;
            int b = 0;
            for (int i = 0; i < sz; i++) {
                if (A.charAt(i) == B.charAt(i)) continue;
                if (A.charAt(i) == 'B') {
                    b++;
                } else {
                    w++;
                }
            }
            sb.append(Math.max(b, w) + "\n");
        }
        System.out.println(sb);
    }
}
