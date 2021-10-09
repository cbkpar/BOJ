import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String str;
        while ((str = br.readLine()) != null) {
            StringTokenizer st = new StringTokenizer(str);
            String A = st.nextToken();
            String B = st.nextToken();
            int asz = A.length();
            int bsz = B.length();
            int p = 0;
            boolean chk = false;
            for (int i = 0; i < bsz; i++) {
                if (B.charAt(i) == A.charAt(p)) {
                    if (++p == asz) {
                        chk = true;
                        break;
                    }
                }
            }
            sb.append(chk ? "Yes\n" : "No\n");
        }
        System.out.println(sb);
    }
}
