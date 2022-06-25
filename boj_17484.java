import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int iN = Integer.parseInt(st.nextToken());
        int iM = Integer.parseInt(st.nextToken());
        int[][][] map = new int[iN + 1][iM][3];
        for (int i = 1; i <= iN; ++i) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < iM; ++j) {
                for (int k = 0; k < 3; ++k) {
                    map[i][j][k] = 1000000000;
                }
                int iFuel = Integer.parseInt(st.nextToken());
                if (j != 0) {
                    map[i][j][2] = Math.min(map[i][j][2], map[i - 1][j - 1][0] + iFuel);
                    map[i][j][2] = Math.min(map[i][j][2], map[i - 1][j - 1][1] + iFuel);
                }
                map[i][j][1] = Math.min(map[i][j][1], map[i - 1][j][0] + iFuel);
                map[i][j][1] = Math.min(map[i][j][1], map[i - 1][j][2] + iFuel);
                if (j + 1 != iM) {
                    map[i][j][0] = Math.min(map[i][j][0], map[i - 1][j + 1][1] + iFuel);
                    map[i][j][0] = Math.min(map[i][j][0], map[i - 1][j + 1][2] + iFuel);
                }
            }
        }
        int iMin = Integer.MAX_VALUE;
        for (int i = 0; i < iM; ++i) {
            for (int j = 0; j < 3; ++j) {
                iMin = Math.min(iMin, map[iN][i][j]);
            }
        }
        System.out.println(iMin);
    }
}
