import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {

    static int[] par;
    static int[] arr;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        arr = new int[n];
        par = new int[n];
        for (int i = 0; i < n; i++) par[i] = i;
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(br.readLine());
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            if (st.nextToken().charAt(0) == '1') {
                int a = Integer.parseInt(st.nextToken()) - 1;
                int b = Integer.parseInt(st.nextToken()) - 1;
                a = find(a);
                b = find(b);
                arr[b] += arr[a];
                union(a, b);
            } else {
                int a = Integer.parseInt(st.nextToken()) - 1;
                int b = Integer.parseInt(st.nextToken()) - 1;
                a = find(a);
                b = find(b);
                arr[b] = Math.abs(arr[a] - arr[b]);
                union(a, b);
            }
        }
        ArrayList<Integer> amount = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (i == par[i] && arr[i] > 0) {
                amount.add(arr[i]);
            }
        }
        Collections.sort(amount);
        sb.append(amount.size() + "\n");
        if (!amount.isEmpty()) sb.append(amount.get(0));
        for (int i = 1; i < amount.size(); i++) sb.append(" " + amount.get(i));
        System.out.println(sb);
    }

    private static int find(int x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);
    }

    private static void union(int x, int y) {
        x = find(x);
        y = find(y);
        par[x] = y;
    }
}
