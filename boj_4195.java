import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {

    static ArrayList<Integer> arr;
    static int[] par;
    static HashMap<String, Integer> map;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int f = Integer.parseInt(br.readLine());
            int cnt = 0;
            arr = new ArrayList<>();
            par = new int[2 * f];
            for (int i = 1; i < 2 * f; i++) par[i] = i;
            map = new HashMap<>();
            while (f-- > 0) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                String A = st.nextToken();
                String B = st.nextToken();
                if (!map.containsKey(A)) {
                    arr.add(1);
                    map.put(A, cnt++);
                }
                if (!map.containsKey(B)) {
                    arr.add(1);
                    map.put(B, cnt++);
                }
                int x = find(map.get(A));
                int y = find(map.get(B));
                union(x, y);
                sb.append(arr.get(x) + "\n");
            }
        }
        System.out.println(sb);
    }

    private static int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    private static void union(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            arr.set(x, arr.get(x) + arr.get(y));
            par[y] = x;
        }
    }
}
