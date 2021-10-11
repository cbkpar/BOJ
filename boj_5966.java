import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            sb.append(check(Integer.parseInt(st.nextToken()), st.nextToken()));
        }
        System.out.println(sb);
    }

    private static String check(int n, String str) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (str.charAt(i) == '>') {
                cnt++;
            } else if (str.charAt(i) == '<') {
                if (cnt == 0) {
                    return "illegal\n";
                } else {
                    cnt--;
                }
            }
        }
        return cnt == 0 ? "legal\n" : "illegal\n";
    }
}
