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
        int[][] matHeight = new int[iN][iM];
        for (int i = 0; i < iN; ++i) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < iM; ++j) {
                matHeight[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int iSurface = 0;
        for (int i = 0; i < iN; ++i) {
            for (int j = 0; j < iM; ++j) {
                iSurface += matHeight[i][j] * 4 + 2;
                if (i != 0) {
                    iSurface -= Math.min(matHeight[i - 1][j], matHeight[i][j]) * 2;
                }
                if (j != 0) {
                    iSurface -= Math.min(matHeight[i][j - 1], matHeight[i][j]) * 2;
                }
            }
        }
        System.out.println(iSurface);
    }
}
