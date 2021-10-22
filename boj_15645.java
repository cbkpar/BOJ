import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] dpmin = new int[n + 1][3];
        int[][] dpmax = new int[n + 1][3];
        for (int i = 1; i <= n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            dpmin[i][0] = Math.min(dpmin[i - 1][0], dpmin[i - 1][1]) + a;
            dpmin[i][1] = Math.min(Math.min(dpmin[i - 1][0], dpmin[i - 1][1]), dpmin[i - 1][2]) + b;
            dpmin[i][2] = Math.min(dpmin[i - 1][1], dpmin[i - 1][2]) + c;
            dpmax[i][0] = Math.max(dpmax[i - 1][0], dpmax[i - 1][1]) + a;
            dpmax[i][1] = Math.max(Math.max(dpmax[i - 1][0], dpmax[i - 1][1]), dpmax[i - 1][2]) + b;
            dpmax[i][2] = Math.max(dpmax[i - 1][1], dpmax[i - 1][2]) + c;
        }
        int mi = Math.min(dpmin[n][0], Math.min(dpmin[n][1], dpmin[n][2]));
        int mx = Math.max(dpmax[n][0], Math.max(dpmax[n][1], dpmax[n][2]));
        System.out.println(mx + " " + mi);
    }
}
