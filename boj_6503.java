import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        while (true) {
            int m = Integer.parseInt(br.readLine());
            if (m == 0) break;
            String str = br.readLine();
            int sz = str.length();
            int l = 0;
            int r = 0;
            int cnt = 1;
            HashMap<Character, Integer> map = new HashMap<>();
            map.put(str.charAt(0), 1);
            while (r < sz) {
                if (cnt <= m) {
                    r++;
                    if (r >= sz) break;
                    if (map.containsKey(str.charAt(r))) {
                        map.put(str.charAt(r), map.get(str.charAt(r)) + 1);
                    } else {
                        map.put(str.charAt(r), 1);
                        cnt++;
                    }
                } else {
                    if (map.get(str.charAt(l)) == 1) {
                        cnt--;
                        map.remove(str.charAt(l));
                    } else {
                        map.put(str.charAt(l), map.get(str.charAt(l)) - 1);
                    }
                    l++;
                    r++;
                    if (r >= sz) break;
                    if (map.containsKey(str.charAt(r))) {
                        map.put(str.charAt(r), map.get(str.charAt(r)) + 1);
                    } else {
                        map.put(str.charAt(r), 1);
                        cnt++;
                    }
                }
            }
            sb.append((r - l) + "\n");
        }
        System.out.println(sb);
    }
}
