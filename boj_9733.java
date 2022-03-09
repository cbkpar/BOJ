import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedHashMap;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        LinkedHashMap<String, Integer> map = new LinkedHashMap<>();
        map.put("Re", 0);
        map.put("Pt", 1);
        map.put("Cc", 2);
        map.put("Ea", 3);
        map.put("Tb", 4);
        map.put("Cm", 5);
        map.put("Ex", 6);
        int[] cnt = new int[7];
        int total = 0;
        String str;
        while ((str = br.readLine()) != null) {
            StringTokenizer st = new StringTokenizer(str);
            while (st.hasMoreTokens()) {
                total++;
                String behave = st.nextToken();
                if (!map.containsKey(behave)) continue;
                cnt[map.get(behave)]++;
            }
        }
        for (String key : map.keySet()) {
            System.out.printf("%s %d %.2f\n", key, cnt[map.get(key)], (float) cnt[map.get(key)] / total);
        }
        System.out.println("Total " + total + " 1.00");
    }
}
