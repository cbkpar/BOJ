import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str = br.readLine();
        int sz = str.length();
        String ans = str;
        for (int i = 1; i < sz - 1; i++) {
            for (int j = i + 1; j < sz; j++) {
                String tmp = "";
                for (int k = i - 1; k >= 0; k--) tmp += str.charAt(k);
                for (int k = j - 1; k >= i; k--) tmp += str.charAt(k);
                for (int k = sz - 1; k >= j; k--) tmp += str.charAt(k);
                if (ans.compareTo(tmp) > 0) ans = tmp;
            }
        }
        System.out.println(ans);
    }
}
