import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            boolean[][] map = new boolean[3][3];
            for (int i = 0; i < 3; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int j = 0; j < 3; j++) if (st.nextToken().charAt(0) == 'T') map[i][j] = true;
            }
            boolean[][] copymap = new boolean[3][3];
            int cnt = 9;
            for (int i = 0; i < 256; i++) {
                for (int p = 0; p < 3; p++) {
                    for (int q = 0; q < 3; q++) copymap[p][q] = map[p][q];
                }
                if ((i & 1 << 0) == 1 << 0) for (int j = 0; j < 3; j++) copymap[0][j] = !copymap[0][j];
                if ((i & 1 << 1) == 1 << 1) for (int j = 0; j < 3; j++) copymap[1][j] = !copymap[1][j];
                if ((i & 1 << 2) == 1 << 2) for (int j = 0; j < 3; j++) copymap[2][j] = !copymap[2][j];
                if ((i & 1 << 3) == 1 << 3) for (int j = 0; j < 3; j++) copymap[j][0] = !copymap[j][0];
                if ((i & 1 << 4) == 1 << 4) for (int j = 0; j < 3; j++) copymap[j][1] = !copymap[j][1];
                if ((i & 1 << 5) == 1 << 5) for (int j = 0; j < 3; j++) copymap[j][2] = !copymap[j][2];
                if ((i & 1 << 6) == 1 << 6) for (int j = 0; j < 3; j++) copymap[j][j] = !copymap[j][j];
                if ((i & 1 << 7) == 1 << 7) for (int j = 0; j < 3; j++) copymap[j][2 - j] = !copymap[j][2 - j];
                boolean ispossible = true;
                for (int j = 1; j < 9; j++)
                    if (copymap[(j - 1) / 3][(j - 1) % 3] != copymap[j / 3][j % 3]) ispossible = false;
                if (ispossible) cnt = Math.min(cnt, Integer.bitCount(i));
            }
            sb.append(cnt == 9 ? "-1\n" : cnt + "\n");
        }
        System.out.println(sb);
    }
}
