import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, p, w, l, g, s;
        boolean chk = true;
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        p = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        w = Integer.parseInt(st.nextToken());
        l = Integer.parseInt(st.nextToken());
        g = Integer.parseInt(st.nextToken());
        s = 0;
        HashSet<String> set = new HashSet<>();
        while (p-- > 0) {
            st = new StringTokenizer(br.readLine());
            String name = st.nextToken();
            if (st.nextToken().charAt(0) == 'W') {
                set.add(name);
            }
        }
        while (n-- > 0) {
            String str = br.readLine();
            if (set.contains(str)) {
                s += w;
                if (s >= g) {
                    chk = false;
                    break;
                }
            } else {
                s = Math.max(s - l, 0);
            }
        }
        System.out.println("I AM" + (chk ? " " : " NOT ") + "IRONMAN!!");
    }
}
