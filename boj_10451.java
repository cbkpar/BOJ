import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {

    static int[] arr;
    static boolean[] chk;
    static HashSet<Integer> set;
    static int cnt;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            arr = new int[n + 1];
            chk = new boolean[n + 1];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= n; i++) arr[i] = Integer.parseInt(st.nextToken());
            cnt = 0;
            for (int i = 1; i <= n; i++) {
                if (!chk[i]) {
                    chk[i] = true;
                    set = new HashSet<>();
                    set.add(i);
                    dfs(i);
                }
            }
            sb.append(cnt + "\n");
        }
        System.out.println(sb);
    }

    private static void dfs(int n) {
        if (set.contains(arr[n])) {
            cnt++;
            return;
        }
        chk[arr[n]] = true;
        set.add(arr[n]);
        dfs(arr[n]);
    }
}
