import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int sz = str.length();
        HashSet<String> set = new HashSet<>();
        int ans = 0;
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j <= sz; j++) {
                String tmp = str.substring(i, j);
                if (set.contains(tmp)) continue;
                set.add(tmp);
                ans++;
            }
        }
        System.out.println(ans);
    }
}
