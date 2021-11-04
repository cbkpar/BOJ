import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] map = new int[n][n];
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < n; j++) {
                if (str.charAt(j) == '#') {
                    map[i][j] = 9;
                } else {
                    map[i][j] = str.charAt(j) - '0';
                }
            }
        }
        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                boolean chk = true;
                for (int p = -1; p <= 1; p++) {
                    for (int q = -1; q <= 1; q++) {
                        if (map[i + p][j + q] <= 0) chk = false;
                    }
                }
                if (chk) {
                    ans++;
                    for (int p = -1; p <= 1; p++) {
                        for (int q = -1; q <= 1; q++) {
                            map[i + p][j + q]--;
                        }
                    }
                }
            }
        }
        System.out.println(ans);
    }
}
