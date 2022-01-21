import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int s = timetonum(st.nextToken());
        int e = timetonum(st.nextToken());
        int r = timetonum(st.nextToken());
        HashSet<String> set = new HashSet<>();
        String str = "";
        int ans = 0;
        while ((str = br.readLine()) != null) {
            st = new StringTokenizer(str);
            int time = timetonum(st.nextToken());
            String name = st.nextToken();
            if (time <= s) {
                set.add(name);
            } else if (time >= e && time <= r) {
                if (set.contains(name)) {
                    ans++;
                    set.remove(name);
                }
            }
        }
        System.out.println(ans);
    }

    private static int timetonum(String str) {
        int tmp = 0;
        tmp += (str.charAt(0) - '0') * 600 + (str.charAt(1) - '0') * 60 + (str.charAt(3) - '0') * 10 + (str.charAt(4) - '0');
        return tmp;
    }
}
