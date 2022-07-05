import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int iN = Integer.parseInt(br.readLine());
        int[] iAccPeople = new int[1001];
        int[][] iStartEnd = new int[iN][2];
        for (int i = 0; i < iN; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            iStartEnd[i][0] = Integer.parseInt(st.nextToken());
            iStartEnd[i][1] = Integer.parseInt(st.nextToken());
            ++iAccPeople[iStartEnd[i][0]];
            --iAccPeople[iStartEnd[i][1]];
        }
        for (int i = 1; i <= 1000; ++i) {
            iAccPeople[i] += iAccPeople[i - 1];
        }
        int iMinCount = 1000;
        for (int i = 0; i < iN; ++i) {
            int iCount = 0;
            for (int j = iStartEnd[i][0]; j < iStartEnd[i][1]; ++j) {
                if (1 == iAccPeople[j]) {
                    ++iCount;
                }
            }
            iMinCount = Math.min(iMinCount, iCount);
        }
        int iMaxTime = 0;
        for (int i = 0; i <= 1000; ++i) {
            if (0 != iAccPeople[i]) {
                ++iMaxTime;
            }
        }
        System.out.println(iMaxTime - iMinCount);
    }
}
