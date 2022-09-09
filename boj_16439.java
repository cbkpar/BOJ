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
        int[][] matCount = new int[iN][iM];
        for (int i = 0; i < iN; ++i) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < iM; ++j) {
                matCount[i][j] += Integer.parseInt(st.nextToken());
            }
        }
        int iMax = 0;
        for (int i = 0; i < iM; ++i) {
            for (int j = i + 1; j < iM; ++j) {
                for (int k = j + 1; k < iM; ++k) {
                    int iTemp = 0;
                    for (int t = 0; t < iN; ++t) {
                        iTemp += Math.max(Math.max(matCount[t][i], matCount[t][j]), matCount[t][k]);

                    }
                    iMax = Math.max(iMax, iTemp);
                }
            }
        }
        System.out.println(iMax);
    }
}
