import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int cnt = 1;
        while (true) {
            String str = br.readLine();
            if (str.equals("0")) break;
            int sz = str.length();
            int odd = 0;
            int even = 0;
            for (int i = sz - 1; i >= 0; i--) {
                if ((sz - i) % 2 == 0) {
                    even += str.charAt(i) - '0';
                } else {
                    odd += str.charAt(i) - '0';
                }
            }
            odd %= 11;
            even %= 11;
            int num = ((even - odd) * (sz % 2 == 0 ? 1 : -1) + 11) % 11;
            if (num >= 1 && num <= 10) {
                sb.append(cnt + ". ");
                for (int i = 0; i < sz; i++) {
                    num = num * 10 + str.charAt(i) - '0';
                    sb.append(num / 11);
                    num %= 11;
                }
                sb.append("\n");
            } else {
                sb.append(cnt + ". IMPOSSIBLE\n");
            }
            cnt++;
        }
        System.out.println(sb);
    }
}
