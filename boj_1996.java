import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static int[] dy = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int[] dx = {-1, 0, 1, -1, 1, -1, 0, 1};

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int iN = Integer.parseInt(br.readLine());
        String[] strMap = new String[iN];
        for (int i = 0; i < iN; ++i) {
            strMap[i] = br.readLine();
        }
        for (int i = 0; i < iN; ++i) {
            for (int j = 0; j < iN; ++j) {
                if (strMap[i].charAt(j) != '.') {
                    sb.append("*");
                } else {
                    int iCount = 0;
                    for (int k = 0; k < 8; ++k) {
                        int iNextY = i + dy[k];
                        int iNextX = j + dx[k];
                        if (iNextX < 0 || iNextX > iN - 1 || iNextY < 0 || iNextY > iN - 1) {
                            continue;
                        }
                        if (strMap[iNextY].charAt(iNextX) != '.') {
                            iCount += strMap[iNextY].charAt(iNextX) - '0';
                        }
                    }
                    if (iCount >= 10) {
                        sb.append("M");
                    } else {
                        sb.append(iCount);
                    }
                }
            }
            sb.append("\n");
        }
        System.out.println(sb);
    }
}
