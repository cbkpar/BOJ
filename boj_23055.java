import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n, i, j;
        n = Integer.parseInt(br.readLine());
        boolean[][] map = new boolean[n][n];
        for (i = 0; i < n; i++) {
            map[0][i] = true;
            map[i][0] = true;
            map[n - 1][i] = true;
            map[i][n - 1] = true;
            map[i][i] = true;
            map[i][n - i - 1] = true;
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                sb.append(map[i][j] ? "*" : " ");
            }
            sb.append("\n");
        }
        System.out.println(sb);
    }
}
