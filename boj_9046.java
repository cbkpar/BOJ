import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        while (n-- > 0) {
            String str = br.readLine();
            int[] cnt = new int[26];
            int sz = str.length();
            for (int i = 0; i < sz; i++) {
                if (str.charAt(i) >= 'a' && str.charAt(i) <= 'z') {
                    cnt[str.charAt(i) - 'a']++;
                }
            }
            ArrayList<Integer> arr = new ArrayList<>();
            int mx = 0;
            for (int i = 0; i < 26; i++) mx = Math.max(mx, cnt[i]);
            for (int i = 0; i < 26; i++) if (cnt[i] == mx) arr.add(i);
            if (arr.size() >= 2) {
                sb.append("?\n");
            } else {
                sb.append((char) (arr.get(0) + 'a') + "\n");
            }
        }
        System.out.println(sb);
    }
}
