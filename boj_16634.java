import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        if (st.nextToken().charAt(0) == 'E') {
            String str = st.nextToken();
            int cnt = 1;
            sb.append(str.charAt(0));
            int sz = str.length();
            if (sz == 1) sb.append("1");
            for (int i = 1; i < sz; i++) {
                if (str.charAt(i) == str.charAt(i - 1)) {
                    cnt++;
                } else {
                    sb.append(cnt + "" + str.charAt(i));
                    cnt = 1;
                }
                if (i == sz - 1) sb.append(cnt);
            }
        } else {
            String str = st.nextToken();
            int sz = str.length();
            for (int i = 0; i < sz; i += 2) {
                for (int j = str.charAt(i + 1); j > '0'; j--) {
                    sb.append(str.charAt(i));
                }
            }
        }
        System.out.println(sb);
    }
}
