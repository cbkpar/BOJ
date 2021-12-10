import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        for (int t = 0; t < 3; t++) {
            int n = Integer.parseInt(br.readLine());
            int sum = 0;
            ArrayList<coin> coins = new ArrayList<>();
            while (n-- > 0) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int value = Integer.parseInt(st.nextToken());
                int amount = Integer.parseInt(st.nextToken());
                coins.add(new coin(value, amount));
                sum += value * amount;
            }
            if (sum % 2 == 1) {
                sb.append("0\n");
                continue;
            }
            sum /= 2;
            boolean[] dp = new boolean[sum + 1];
            dp[0] = true;
            for (coin c : coins) {
                int value = c.value;
                int amount = c.amount;
                for (int i = sum - value; i >= 0; i--) {
                    if (!dp[i]) continue;
                    for (int j = 1; j <= amount; j++) {
                        if (i + j * value > sum) break;
                        dp[i + j * value] = true;
                    }
                    if (dp[sum]) break;
                }
            }
            sb.append(dp[sum] ? "1\n" : "0\n");
        }
        System.out.println(sb);
    }
}

class coin {
    int value;
    int amount;

    public coin(int value, int amount) {
        this.value = value;
        this.amount = amount;
    }
}
