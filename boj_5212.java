import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static boolean[][] bArrMap;
    static int iR, iC;
    static int[] dR = {-1, 0, 1, 0};
    static int[] dC = {0, -1, 0, 1};

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        iR = Integer.parseInt(st.nextToken());
        iC = Integer.parseInt(st.nextToken());
        bArrMap = new boolean[iR][iC];
        for (int i = 0; i < iR; ++i) {
            String str = br.readLine();
            for (int j = 0; j < iC; ++j) {
                if (str.charAt(j) == 'X') bArrMap[i][j] = true;
            }
        }
        boolean[][] bArrNextMap = new boolean[iR][iC];
        int iRMin = iR - 1;
        int iRMax = 0;
        int iCMin = iC - 1;
        int iCMax = 0;
        for (int i = 0; i < iR; ++i) {
            for (int j = 0; j < iC; ++j) {
                if (bArrMap[i][j]) {
                    if (FloodCheck(i, j)) {
                        bArrNextMap[i][j] = true;
                        iRMin = Math.min(iRMin, i);
                        iRMax = Math.max(iRMax, i);
                        iCMin = Math.min(iCMin, j);
                        iCMax = Math.max(iCMax, j);
                    }
                }
            }
        }
        for (int i = iRMin; i <= iRMax; ++i) {
            for (int j = iCMin; j <= iCMax; ++j) {
                sb.append(bArrNextMap[i][j] ? "X" : ".");
            }
            sb.append("\n");
        }
        System.out.println(sb);
    }

    private static boolean FloodCheck(int _iR, int _iC) {
        int iCount = 0;
        for (int i = 0; i < 4; ++i) {
            int m_iR = _iR + dR[i];
            int m_iC = _iC + dC[i];
            if (m_iR < 0 || m_iR > iR - 1 || m_iC < 0 || m_iC > iC - 1) continue;
            if (bArrMap[m_iR][m_iC]) ++iCount;
        }
        if (iCount < 2) {
            return false;
        }
        return true;
    }
}
