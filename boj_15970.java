import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        ArrayList<Integer>[] arr = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) arr[i] = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            arr[b].add(a);
        }
        long ans = 0;
        for (int i = 1; i <= n; i++) {
            if (arr[i].size() == 0) continue;
            Collections.sort(arr[i]);
            int sz = arr[i].size();
            for (int j = 0; j < sz; j++) {
                int dist = Integer.MAX_VALUE;
                if (j != 0) dist = Math.min(dist, arr[i].get(j) - arr[i].get(j - 1));
                if (j != sz - 1) dist = Math.min(dist, arr[i].get(j + 1) - arr[i].get(j));
                ans += dist;
            }
        }
        System.out.println(ans);
    }
}
