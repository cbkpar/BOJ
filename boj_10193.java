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
            StringTokenizer st = new StringTokenizer(br.readLine());
            String A = st.nextToken();
            String B = st.nextToken();
            int coins = 0;
            int sz = A.length();
            for (int i = 0; i < sz; i++) coins += A.charAt(i) - B.charAt(i);
            if (coins > 0) {
                sb.append("Swapping letters to make " + A + " look like " + B + " earned " + coins + " coins.\n");
            } else if (coins == 0) {
                sb.append("Swapping letters to make " + A + " look like " + B + " was FREE.\n");
            } else {
                sb.append("Swapping letters to make " + A + " look like " + B + " cost " + (-coins) + " coins.\n");
            }
        }
        System.out.println(sb);
    }
}
