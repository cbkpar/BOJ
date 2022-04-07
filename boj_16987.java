import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int[][] eggs;
    static int[] arr;
    static int n;
    static int mx = 0;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        eggs = new int[n][2];
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            eggs[i][0] = Integer.parseInt(st.nextToken());
            eggs[i][1] = Integer.parseInt(st.nextToken());
        }
        dfs(0);
        System.out.println(mx);
    }

    private static void dfs(int k) {
        if (k == n) {
            int[][] c_eggs = new int[n][2];
            for (int i = 0; i < n; i++) {
                c_eggs[i][0] = eggs[i][0];
                c_eggs[i][1] = eggs[i][1];
            }
            for (int i = 0; i < n; i++) {
                if (c_eggs[i][0] <= 0) continue;
                if (c_eggs[arr[i]][0] <= 0) continue;
                c_eggs[arr[i]][0] -= c_eggs[i][1];
                c_eggs[i][0] -= c_eggs[arr[i]][1];
            }
            int cnt = 0;
            for (int i = 0; i < n; i++) if (c_eggs[i][0] <= 0) cnt++;
            mx = Math.max(mx, cnt);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (i == k) continue;
            arr[k] = i;
            dfs(k + 1);
        }
    }
}
