import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static int[] dR = {-1, 0, 1, 0};
    static int[] dC = {0, -1, 0, 1};

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[][] matState = new int[5][5];
        boolean[][] matIsVisited = new boolean[5][5];
        for (int i = 0; i < 5; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 5; ++j) {
                matState[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        Queue<CPos> qPos = new LinkedList<>();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int iR = Integer.parseInt(st.nextToken());
        int iC = Integer.parseInt(st.nextToken());
        qPos.add(new CPos(iR, iC));
        matIsVisited[iR][iC] = true;
        int iCount = 0;
        while (!qPos.isEmpty()) {
            int iSize = qPos.size();
            while (iSize-- > 0) {
                CPos NowPos = qPos.poll();
                int NowR = NowPos.getR();
                int NowC = NowPos.getC();
                if (1 == matState[NowR][NowC]) {
                    System.out.println(iCount);
                    return;
                }
                for (int i = 0; i < 4; ++i) {
                    int NextR = NowR + dR[i];
                    int NextC = NowC + dC[i];
                    if (NextR < 0 || NextR > 4 || NextC < 0 || NextC > 4 || matIsVisited[NextR][NextC]) {
                        continue;
                    }
                    if (-1 == matState[NextR][NextC]) {
                        continue;
                    }
                    qPos.add(new CPos(NextR, NextC));
                    matIsVisited[NextR][NextC] = true;
                }
            }
            ++iCount;
        }
        System.out.println("-1");
    }
}

class CPos {
    public CPos(int iR, int iC) {
        this.iR = iR;
        this.iC = iC;
    }

    public int getR() {
        return iR;
    }

    public int getC() {
        return iC;
    }

    private int iR, iC;
}
