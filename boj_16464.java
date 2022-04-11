import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        while (n-- > 0) {
            int k = Integer.parseInt(br.readLine());
            if (k % 2 == 1) {
                sb.append("Gazua\n");
            } else {
                boolean ispossible = false;
                k -= 3;
                for (int i = 3; i <= k; i++) {
                    if (k % i == 0) {
                        ispossible = true;
                        break;
                    }
                    k -= i;
                    if (k < 0) break;
                }
                sb.append(ispossible ? "Gazua\n" : "GoHanGang\n");
            }
        }
        System.out.println(sb);
    }
}
