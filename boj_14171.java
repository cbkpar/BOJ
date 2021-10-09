import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        HashMap<String, Integer> map = new HashMap<>();
        int n = Integer.parseInt(br.readLine());
        long ans = 0;
        while (n-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String A = st.nextToken().substring(0, 2);
            String B = st.nextToken().substring(0, 2);
            if (A.equals(B)) continue;
            if (map.containsKey(B.concat(A))) {
                ans += map.get(B.concat(A));
            }
            if (map.containsKey(A.concat(B))) {
                map.put(A.concat(B), map.get(A.concat(B)) + 1);
            } else {
                map.put(A.concat(B), 1);
            }
        }
        System.out.println(ans);
    }
}
