import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int sz = str.length();
        boolean[] chk = new boolean[sz + 1];
        for (int i = 1; i <= sz; i++) if (str.charAt(i - 1) == 'Y') chk[i] = true;
        int cnt = 0;
        for (int i = 1; i <= sz; i++) {
            if (chk[i]) {
                for (int j = i; j <= sz; j += i) chk[j] = !chk[j];
                cnt++;
            }
        }
        System.out.println(cnt);
    }
}
