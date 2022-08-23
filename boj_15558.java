import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int iN = Integer.parseInt(st.nextToken());
        int iK = Integer.parseInt(st.nextToken());
        boolean[][] matIsImpossible = new boolean[iN + 1][2];
        for (int i = 0; i < 2; ++i) {
            String str = br.readLine();
            int iSize = str.length();
            for (int j = 1; j <= iSize; ++j) {
                if (str.charAt(j - 1) == '0') {
                    matIsImpossible[j][i] = true;
                }
            }
        }
        Queue<CPos> qPos = new LinkedList<>();
        qPos.add(new CPos(1, 0));
        matIsImpossible[1][0] = true;
        int iCount = 0;
        while (!qPos.isEmpty()) {
            ++iCount;
            int iSize = qPos.size();
            while (iSize-- > 0) {
                CPos Pos = qPos.poll();
                if (Pos.iHeight + iK >= iN + 1) {
                    System.out.println("1");
                    return;
                }
                if (Pos.iHeight + 1 <= iN && !matIsImpossible[Pos.iHeight + 1][Pos.iDir]) {
                    matIsImpossible[Pos.iHeight + 1][Pos.iDir] = true;
                    qPos.add(new CPos(Pos.iHeight + 1, Pos.iDir));
                }
                if (Pos.iHeight - 1 > 0 && Pos.iHeight - 1 > iCount && !matIsImpossible[Pos.iHeight - 1][Pos.iDir]) {
                    matIsImpossible[Pos.iHeight - 1][Pos.iDir] = true;
                    qPos.add(new CPos(Pos.iHeight - 1, Pos.iDir));
                }
                if (Pos.iHeight + iK <= iN && !matIsImpossible[Pos.iHeight + iK][(Pos.iDir + 1) % 2]) {
                    matIsImpossible[Pos.iHeight + iK][(Pos.iDir + 1) % 2] = true;
                    qPos.add(new CPos(Pos.iHeight + iK, (Pos.iDir + 1) % 2));
                }
            }
        }
        System.out.println("0");
    }
}

class CPos {
    int iHeight, iDir;

    public CPos(int iHeight, int iDir) {
        this.iHeight = iHeight;
        this.iDir = iDir;
    }
}
