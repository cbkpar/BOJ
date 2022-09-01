import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] dR = {-1, -1, -1, 0, 0, 1, 1, 1};
        int[] dC = {-1, 0, 1, -1, 1, -1, 0, 1};
        StringTokenizer st = new StringTokenizer(br.readLine());
        int iN = Integer.parseInt(st.nextToken());
        int iM = Integer.parseInt(st.nextToken());
        int[][] matMap = new int[iN][iM];
        boolean[][] matVisited = new boolean[iN][iM];
        for (int i = 0; i < iN; ++i) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < iM; ++j) {
                matMap[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int iCount = 0;
        for (int i = 0; i < iN; ++i) {
            for (int j = 0; j < iM; ++j) {
                if (!matVisited[i][j] && matMap[i][j] == 1) {
                    Queue<Pos> qPos = new LinkedList<>();
                    qPos.add(new Pos(i, j));
                    matVisited[i][j] = true;
                    ++iCount;
                    while (!qPos.isEmpty()) {
                        Pos p = qPos.poll();
                        int iR = p.iR;
                        int iC = p.iC;
                        for (int k = 0; k < 8; ++k) {
                            int iNextR = iR + dR[k];
                            int iNextC = iC + dC[k];
                            if (iNextR < 0 || iNextR > iN - 1 || iNextC < 0 || iNextC > iM - 1) {
                                continue;
                            }
                            if (!matVisited[iNextR][iNextC] && matMap[iNextR][iNextC] == 1) {
                                qPos.add(new Pos(iNextR, iNextC));
                                matVisited[iNextR][iNextC] = true;
                            }
                        }

                    }
                }
            }
        }
        System.out.println(iCount);
    }
}

class Pos {
    int iR, iC;

    public Pos(int iR, int iC) {
        this.iR = iR;
        this.iC = iC;
    }
}
