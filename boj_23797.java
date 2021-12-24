import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int k = 0;
        int p = 0;
        int mx = 0;
        int sz = str.length();
        for (int i = 0; i < sz; i++) {
            if (str.charAt(i) == 'K') {
                if (k != 0) k--;
                p++;
            } else {
                if (p != 0) p--;
                k++;
            }
            mx = Math.max(mx, k + p);
        }
        System.out.println(mx);
    }
}
