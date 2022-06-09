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
        int[][] ArrMap = new int[iN][iM];
        int iSum = 0;
        for (int i = 0; i < iN; ++i) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < iM; ++j) {
                int iNum = Integer.parseInt(st.nextToken());
                while (iNum > 0) {
                    if (9 == iNum % 10) {
                        ++ArrMap[i][j];
                        ++iSum;
                    }
                    iNum /= 10;
                }
            }
        }
        int iMax = 0;
        for (int i = 0; i < iN; ++i) {
            int iCount = 0;
            for (int j = 0; j < iM; ++j) {
                iCount += ArrMap[i][j];
            }
            iMax = Math.max(iMax, iCount);
        }
        for (int i = 0; i < iM; ++i) {
            int iCount = 0;
            for (int j = 0; j < iN; ++j) {
                iCount += ArrMap[j][i];
            }
            iMax = Math.max(iMax, iCount);
        }
        System.out.println(iSum - iMax);
    }
}
