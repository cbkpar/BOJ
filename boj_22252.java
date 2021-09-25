import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int q, i, t, k;
        long s;
        q = Integer.parseInt(br.readLine());
        ArrayList<Integer>[] arr = new ArrayList[q];
        HashMap<String, Integer> map = new HashMap<>();
        s = 0;
        for (i = 0; i < q; i++) arr[i] = new ArrayList<Integer>();
        for (i = 0; i < q; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            if (st.nextToken().charAt(0) == '1') {
                String str = st.nextToken();
                t = i;
                if (map.containsKey(str)) t = map.get(str);
                map.put(str, t);
                k = Integer.parseInt(st.nextToken());
                while (k-- > 0) arr[t].add(Integer.parseInt(st.nextToken()));
            } else {
                String str = st.nextToken();
                if (!map.containsKey(str)) continue;
                t = map.get(str);
                Collections.sort(arr[t], Collections.reverseOrder());
                k = Integer.parseInt(st.nextToken());
                k = Math.min(k - 1, arr[t].size() - 1);
                while (k-- >= 0) s += arr[t].remove(0);
            }
        }
        System.out.println(s);
    }
}
