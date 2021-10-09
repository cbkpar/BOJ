import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            HashSet<String> set = new HashSet<>();
            while (true) {
                String str = br.readLine();
                if (str.equals("what does the fox say?")) break;
                StringTokenizer tmpst = new StringTokenizer(str);
                tmpst.nextToken();
                tmpst.nextToken();
                set.add(tmpst.nextToken());
            }
            boolean chk = false;
            while (st.hasMoreTokens()) {
                String str = st.nextToken();
                if (set.contains(str)) continue;
                if (chk) sb.append(" ");
                sb.append(str);
                chk = true;
            }
            sb.append("\n");
        }
        System.out.println(sb);
    }
}
