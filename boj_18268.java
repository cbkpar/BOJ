import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {


    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int iN = Integer.parseInt(st.nextToken());
        int iK = Integer.parseInt(st.nextToken());
        int[][] matRank = new int[iN][iK];
        for (int i = 0; i < iN; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < iK; ++j) {
                matRank[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        boolean[][] matIsWin = new boolean[iK + 1][iK + 1];
        for (int i = 1; i <= iK; ++i) {
            for (int j = 1; j <= iK; ++j) {
                if (i == j) continue;
                matIsWin[i][j] = true;
            }
        }
        for (int i = 0; i < iN; ++i) {
            for (int j = 0; j < iK; ++j) {
                for (int k = j + 1; k < iK; ++k) {
                    matIsWin[matRank[i][j]][matRank[i][k]] = false;
                }
            }
        }
        int iCount = 0;
        for (int i = 1; i <= iK; ++i) {
            for (int j = 1; j <= iK; ++j) {
                if (matIsWin[i][j]) {
                    ++iCount;
                }
            }
        }
        System.out.println(iCount);
    }
}
