import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int iH = Integer.parseInt(st.nextToken());
            int iW = Integer.parseInt(st.nextToken());
            if (0 == iH && 0 == iW) break;
            int iDiag = Diag(iH, iW);
            int iMinDiag = Integer.MAX_VALUE;
            int iNewH = 0;
            int iNewW = 0;
            for (int i = 1; i <= 149; ++i) {
                for (int j = i + 1; j <= 150; ++j) {
                    if (iH == i && iW == j) continue;
                    int iNewDiag = Diag(i, j);
                    if (iNewDiag >= iDiag && iMinDiag > iNewDiag) {
                        if (iNewDiag == iDiag && i < iH) continue;
                        iMinDiag = iNewDiag;
                        iNewH = i;
                        iNewW = j;
                    }
                }
            }
            sb.append(iNewH + " " + iNewW + "\n");
        }
        System.out.println(sb);
    }

    private static int Diag(int _iH, int _iW) {
        return _iH * _iH + _iW * _iW;
    }
}
