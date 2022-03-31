import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n;
    static int diff;
    static int[][] arr;
    static int[] gomduri;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new int[n][3];
        for (int i = 0; i < n; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken());
            arr[i][2] = Integer.parseInt(st.nextToken());
        }
        gomduri = new int[3];
        StringTokenizer st = new StringTokenizer(br.readLine());
        gomduri[0] = Integer.parseInt(st.nextToken());
        gomduri[1] = Integer.parseInt(st.nextToken());
        gomduri[2] = Integer.parseInt(st.nextToken());
        diff = Integer.MAX_VALUE;
        dfs(0, 0, 0, 0, 0);
        System.out.println(diff);
    }

    public static void dfs(int t, int k, int r, int g, int b) {
        if (k >= 2) {
            int tr = r / k;
            int tg = g / k;
            int tb = b / k;
            int tsum = Math.abs(tr - gomduri[0]) + Math.abs(tg - gomduri[1]) + Math.abs(tb - gomduri[2]);
            diff = Math.min(diff, tsum);
        }
        if (k < 7) {
            for (int i = t; i < n; i++) {
                dfs(i + 1, k + 1, r + arr[i][0], g + arr[i][1], b + arr[i][2]);
            }
        }
    }
}
