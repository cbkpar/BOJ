import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        while (n-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            boolean[] A = new boolean[26];
            boolean[] B = new boolean[26];
            boolean chk = true;
            String str = st.nextToken();
            int sz = str.length();
            for (int i = 0; i < sz; i++) A[str.charAt(i) - 'A'] = true;
            str = st.nextToken();
            sz = str.length();
            for (int i = 0; i < sz; i++) B[str.charAt(i) - 'A'] = true;
            for (int i = 0; i < 26; i++) {
                if (A[i] != B[i]) {
                    chk = false;
                    break;
                }
            }
            sb.append(chk ? "YES\n" : "NO\n");
        }
        System.out.println(sb);
    }
}
