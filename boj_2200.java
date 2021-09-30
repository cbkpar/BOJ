import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, i, t, cnt;
        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        cnt = 2 * n;
        st.nextToken();
        for (i = n - 1; i >= 0; i--) {
            String str = st.nextToken();
            t = Integer.parseInt(str);
            if (t != 0) cnt += str.length() + 1;
        }
        System.out.println(cnt);
    }
}
