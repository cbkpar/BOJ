import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int cnt;
    static int[][] score;
    static boolean[] team;
    static int mi = Integer.MAX_VALUE;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        cnt = Integer.parseInt(br.readLine());
        score = new int[cnt][cnt];
        for (int i = 0; i < cnt; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < cnt; j++) score[i][j] = Integer.parseInt(st.nextToken());
        }
        team = new boolean[cnt];
        dfs(0);
        System.out.println(mi);
    }

    private static void dfs(int n) {
        if (n == cnt) {
            mi = Math.min(mi, calc());
            return;
        }
        team[n] = true;
        dfs(n + 1);
        team[n] = false;
        dfs(n + 1);
    }

    private static int calc() {
        int tscore = 0;
        for (int i = 0; i < cnt; i++) {
            for (int j = 0; j < cnt; j++) {
                if (i == j) continue;
                if (team[i] == team[j]) {
                    tscore += team[i] ? score[i][j] : -score[i][j];
                }
            }
        }
        return Math.abs(tscore);
    }
}
