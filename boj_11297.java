import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            if (a == 0 && b == 0 && c == 0) break;
            a += b + c;
            a %= 25;
            a++;
            String str = br.readLine();
            int sz = str.length();
            for (int i = 0; i < sz; i++) {
                if (str.charAt(i) >= 'a' && str.charAt(i) <= 'z') {
                    sb.append((char) ((str.charAt(i) - 'a' - a + 26)%26 + 'a'));
                } else {
                    sb.append(str.charAt(i));
                }
            }
            sb.append("\n");
        }
        System.out.println(sb);
    }
}
