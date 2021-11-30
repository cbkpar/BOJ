import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        while (n-- > 0) {
            String str = br.readLine();
            int sz = str.length();
            boolean chk = true;
            int[] cnt = new int[26];
            for (int i = 0; i < sz; i++) {
                int t = str.charAt(i) - 'A';
                if (++cnt[t] % 3 == 0) {
                    if (i == sz - 1) {
                        chk = false;
                        break;
                    }
                    if (str.charAt(i) != str.charAt(i + 1)) {
                        chk = false;
                        break;
                    }
                    i++;
                }
            }
            sb.append(chk ? "OK\n" : "FAKE\n");
        }
        System.out.println(sb);
    }
}
