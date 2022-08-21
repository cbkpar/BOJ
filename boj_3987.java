import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static String[] matMap;
    static boolean[][][] bIsVisited;
    static int iAns, iN, iM;
    static int[] dR = {-1, 0, 1, 0};
    static int[] dC = {0, -1, 0, 1};

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        iN = Integer.parseInt(st.nextToken());
        iM = Integer.parseInt(st.nextToken());
        matMap = new String[iN];
        for (int i = 0; i < iN; ++i) {
            matMap[i] = br.readLine();
        }
        st = new StringTokenizer(br.readLine());
        int iR = Integer.parseInt(st.nextToken()) - 1;
        int iC = Integer.parseInt(st.nextToken()) - 1;
        int iMaxNum = -1;
        int iMaxCount = -1;
        for (int i = 0; i < 4; ++i) {
            iAns = 0;
            bIsVisited = new boolean[iN][iM][4];
            dfs(iR, iC, (4 - i) % 4, 1);
            if (iAns > iMaxCount) {
                iMaxNum = (4 - i) % 4;
                iMaxCount = iAns;
            }
        }
        switch (iMaxNum) {
            case 0:
                System.out.println("U");
                break;
            case 1:
                System.out.println("L");
                break;
            case 2:
                System.out.println("D");
                break;
            case 3:
                System.out.println("R");
                break;
        }
        System.out.println((iMaxCount == 1000000000 ? "Voyager" : iMaxCount));
    }

    private static void dfs(int iR, int iC, int iDir, int iS) {
        bIsVisited[iR][iC][iDir] = true;
        int iNextR = iR + dR[iDir];
        int iNextC = iC + dC[iDir];
        if (iNextR < 0 || iNextR > iN - 1 || iNextC < 0 || iNextC > iM - 1) {
            iAns = Math.max(iAns, iS);
            return;
        }
        if (bIsVisited[iNextR][iNextC][iDir]) {
            iAns = 1000000000;
            return;
        }
        switch (matMap[iNextR].charAt(iNextC)) {
            case '.':
                break;
            case '/':
                iDir = 3 - iDir;
                break;
            case '\\':
                iDir += (iDir % 2 == 0 ? 1 : -1);
                break;
            case 'C':
                iAns = Math.max(iAns, iS);
                return;
        }
        dfs(iNextR, iNextC, iDir, iS + 1);
    }
}
