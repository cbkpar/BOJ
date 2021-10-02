import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n, sz, i, t;
        n = Integer.parseInt(br.readLine());
        HashSet<Character> set = new HashSet<>();
        while (n-- > 0) {
            String str = convert(br.readLine());
            String tstr = str.toLowerCase();
            sz = str.length();
            boolean chk = false;
            if (!set.contains(tstr.charAt(0))) {
                sb.append("[" + str.charAt(0) + "]" + str.substring(1) + "\n");
                set.add(tstr.charAt(0));
                continue;
            }
            t = 0;
            for (i = 1; i < sz; i++) {
                if (tstr.charAt(i - 1) == ' ') {
                    if (!set.contains(tstr.charAt(i))) {
                        t = i;
                        chk = true;
                        break;
                    }
                } else {
                    if (chk||tstr.charAt(i)==' ') continue;
                    if (!set.contains(tstr.charAt(i))) {
                        t = i;
                        chk = true;
                    }
                }
            }
            if (chk) {
                sb.append(str.substring(0, t) + "[" + str.charAt(t) + "]" + str.substring(t + 1) + "\n");
                set.add(tstr.charAt(t));
            } else {
                sb.append(str + "\n");
            }
        }
        System.out.println(sb);
    }

    public static String convert(String str){
        StringTokenizer st = new StringTokenizer(str);
        StringBuilder sb = new StringBuilder();
        sb.append(st.nextToken());
        while(st.hasMoreTokens()) sb.append(" "+st.nextToken());
        return sb.toString();
    }
}
