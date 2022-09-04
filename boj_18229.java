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
        int iK = Integer.parseInt(st.nextToken());
        int[][] matCount = new int[iN + 1][iM + 1];
        for (int i = 1; i <= iN; ++i) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= iM; ++j) {
                matCount[i][j] = matCount[i][j - 1] + Integer.parseInt(st.nextToken());
            }
        }
        for (int i = 1; i <= iM; ++i) {
            for (int j = 1; j <= iN; ++j) {
                if (matCount[j][i] >= iK) {
                    System.out.println(j + " " + i);
                    return;
                }
            }
        }
    }
}
