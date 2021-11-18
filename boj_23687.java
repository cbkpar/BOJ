import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        int a = 0;
        int b = 0;
        int c = 0;
        while (n-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String str = st.nextToken();
            if (str.equals("section")) {
                a++;
                b = c = 0;
            } else if (str.equals("subsection")) {
                b++;
                c = 0;
            } else {
                c++;
            }
            str = st.nextToken();
            sb.append(a);
            if (b != 0) sb.append("." + b);
            if (c != 0) sb.append("." + c);
            sb.append(" " + str + "\n");
        }
        System.out.println(sb);
    }
}
