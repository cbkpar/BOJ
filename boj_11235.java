import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n, t, mx;
        n = Integer.parseInt(br.readLine());
        mx = 1;
        HashMap<String, Integer> map = new HashMap<>();
        while (n-- > 0) {
            String str = br.readLine();
            if (map.containsKey(str)) {
                t = map.get(str) + 1;
                map.put(str, t);
                mx = Math.max(mx, t);
            } else {
                map.put(str, 1);
            }
        }
        ArrayList<String> candidate = new ArrayList<>();
        for (String k : map.keySet()) {
            if (map.get(k) == mx) candidate.add(k);
        }
        Collections.sort(candidate);
        for (String k : candidate) sb.append(k + "\n");
        System.out.println(sb);
    }
}
