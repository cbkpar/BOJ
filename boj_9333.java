import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        while (n-- > 0) {
            String str = br.readLine().replaceAll("[.]", "");
            StringTokenizer st = new StringTokenizer(str);
            long R = Long.parseLong(st.nextToken());
            long B = Long.parseLong(st.nextToken());
            long M = Long.parseLong(st.nextToken());
            int day = 0;
            boolean ispossible = false;
            for (int i = 0; i < 1200; i++) {
                long next = B * (10000 + R)/100;
                next = (next / 100 + (next % 100 >= 50 ? 1 : 0)) - M;
                if (next >= B) break;
                day++;
                if (next <= 0) {
                    ispossible = true;
                    break;
                }
                B = next;
            }
            sb.append(ispossible ? day + "\n" : "impossible\n");
        }
        System.out.println(sb);
    }
}
