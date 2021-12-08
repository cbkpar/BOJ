import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int[][] map;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        map = new int[n][n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) map[i][j] = Integer.parseInt(st.nextToken());
        }
        System.out.println(divide(0, 0, n));
    }

    private static int divide(int r, int c, int n) {
        if (n == 1) {
            return map[r][c];
        }
        int[] arr = new int[4];
        arr[0] = divide(r, c, n / 2);
        arr[1] = divide(r + n / 2, c, n / 2);
        arr[2] = divide(r, c + n / 2, n / 2);
        arr[3] = divide(r + n / 2, c + n / 2, n / 2);
        Arrays.sort(arr);
        return arr[2];
    }
}
