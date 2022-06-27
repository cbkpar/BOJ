import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int[][] Map = new int[3][3];
    static int[][] tempMap = new int[3][3];
    static boolean[] visited = new boolean[9];
    static int MinDiff = Integer.MAX_VALUE;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for (int i = 0; i < 3; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 3; ++j) {
                Map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        dfs(0);
        System.out.println(MinDiff);
    }

    public static void dfs(int k) {
        if (9 == k) {
            for (int i = 0; i < 3; ++i) {
                if (15 != tempMap[i][0] + tempMap[i][1] + tempMap[i][2]) {
                    return;
                }
            }
            for (int i = 0; i < 3; ++i) {
                if (15 != tempMap[0][i] + tempMap[1][i] + tempMap[2][i]) {
                    return;
                }
            }
            if (15 != tempMap[0][0] + tempMap[1][1] + tempMap[2][2]) {
                return;
            }
            if (15 != tempMap[2][0] + tempMap[1][1] + tempMap[0][2]) {
                return;
            }
            int iDiff = 0;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    iDiff += Math.abs(tempMap[i][j] - Map[i][j]);
                }
            }
            MinDiff = Math.min(MinDiff, iDiff);
            return;
        }
        for (int i = 0; i < 9; ++i) {
            if (!visited[i]) {
                visited[i] = true;
                tempMap[k / 3][k % 3] = i + 1;
                dfs(k + 1);
                visited[i] = false;
            }
        }
    }
}
