import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, i, j, t;
        n = Integer.parseInt(br.readLine());
        int[][] map = new int[n][n];
        HashSet<Integer> set = new HashSet<>();
        for (i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (j = 0; j < n; j++) {
                t = Integer.parseInt(st.nextToken());
                if (t <= 0 || t > n * n || set.contains(t)) {
                    System.out.println("FALSE");
                    return;
                }
                map[i][j] = t;
                set.add(t);
            }
        }
        for (i = 0; i < n; i++) {
            t = 0;
            for (j = 0; j < n; j++) t += map[i][j];
            if (t != (n * (n * n + 1)) / 2) {
                System.out.println("FALSE");
                return;
            }
        }
        for (i = 0; i < n; i++) {
            t = 0;
            for (j = 0; j < n; j++) t += map[j][i];
            if (t != (n * (n * n + 1)) / 2) {
                System.out.println("FALSE");
                return;
            }
        }
        t = 0;
        for (i = 0; i < n; i++) t += map[i][i];
        if (t != (n * (n * n + 1)) / 2) {
            System.out.println("FALSE");
            return;
        }
        t = 0;
        for (i = 0; i < n; i++) t += map[i][n-i-1];
        if (t != (n * (n * n + 1)) / 2) {
            System.out.println("FALSE");
            return;
        }
        System.out.println("TRUE");
    }
}
