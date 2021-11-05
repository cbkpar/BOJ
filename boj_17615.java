import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int sz = Integer.parseInt(br.readLine());
        String str = br.readLine();
        int ans = Integer.MAX_VALUE;
        for (int i = sz - 1; i >= 0; i--) {
            if (str.charAt(i) == 'B') {
                int tmp = 0;
                for (int j = i - 1; j >= 0; j--) {
                    if (str.charAt(j) == 'R') tmp++;
                }
                ans = Math.min(ans, tmp);
                break;
            }
        }
        for (int i = 0; i < sz; i++) {
            if (str.charAt(i) == 'B') {
                int tmp = 0;
                for (int j = i + 1; j <sz; j++) {
                    if (str.charAt(j) == 'R') tmp++;
                }
                ans = Math.min(ans, tmp);
                break;
            }
        }
        for (int i = sz - 1; i >= 0; i--) {
            if (str.charAt(i) == 'R') {
                int tmp = 0;
                for (int j = i - 1; j >= 0; j--) {
                    if (str.charAt(j) == 'B') tmp++;
                }
                ans = Math.min(ans, tmp);
                break;
            }
        }
        for (int i = 0; i < sz; i++) {
            if (str.charAt(i) == 'R') {
                int tmp = 0;
                for (int j = i + 1; j <sz; j++) {
                    if (str.charAt(j) == 'B') tmp++;
                }
                ans = Math.min(ans, tmp);
                break;
            }
        }
        System.out.println(ans);
    }
}
