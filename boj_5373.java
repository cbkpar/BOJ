import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int[][][] map = new int[6][3][3];
    static int[] tmp = new int[3];

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        char[] arr = "gyowrb".toCharArray();
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            init();
            int n = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            while (n-- > 0) command(st.nextToken());
            for (int i = 2; i >= 0; i--) {
                for (int j = 0; j < 3; j++) {
                    sb.append(arr[map[3][i][j]]);
                }
                sb.append("\n");
            }
        }
        System.out.println(sb);
    }

    private static void init() {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    map[i][j][k] = i;
                }
            }
        }
    }

    private static void command(String co) {
        int times = co.charAt(1) == '+' ? 3 : 1;
        if (co.charAt(0) == 'L') while (times-- > 0) lminus();
        if (co.charAt(0) == 'R') while (times-- > 0) rminus();
        if (co.charAt(0) == 'U') while (times-- > 0) uminus();
        if (co.charAt(0) == 'D') while (times-- > 0) dminus();
        if (co.charAt(0) == 'F') while (times-- > 0) fminus();
        if (co.charAt(0) == 'B') while (times-- > 0) bminus();
    }

    private static void uminus() {
        for (int i = 0; i < 3; i++) tmp[i] = map[2][0][i];
        for (int i = 0; i < 3; i++) map[2][0][i] = map[5][2 - i][0];
        for (int i = 0; i < 3; i++) map[5][2 - i][0] = map[4][2][2 - i];
        for (int i = 0; i < 3; i++) map[4][2][2 - i] = map[0][i][2];
        for (int i = 0; i < 3; i++) map[0][i][2] = tmp[i];
        protate(3);
    }

    private static void dminus() {
        for (int i = 0; i < 3; i++) tmp[i] = map[0][2 - i][0];
        for (int i = 0; i < 3; i++) map[0][2 - i][0] = map[4][0][i];
        for (int i = 0; i < 3; i++) map[4][0][i] = map[5][i][2];
        for (int i = 0; i < 3; i++) map[5][i][2] = map[2][2][2 - i];
        for (int i = 0; i < 3; i++) map[2][2][2 - i] = tmp[i];
        protate(1);
    }

    private static void lminus() {
        for (int i = 0; i < 3; i++) tmp[i] = map[1][2 - i][0];
        for (int i = 0; i < 3; i++) map[1][2 - i][0] = map[2][2 - i][0];
        for (int i = 0; i < 3; i++) map[2][2 - i][0] = map[3][2 - i][0];
        for (int i = 0; i < 3; i++) map[3][2 - i][0] = map[4][2 - i][0];
        for (int i = 0; i < 3; i++) map[4][2 - i][0] = tmp[i];
        protate(0);
    }

    private static void rminus() {
        for (int i = 0; i < 3; i++) tmp[i] = map[4][i][2];
        for (int i = 0; i < 3; i++) map[4][i][2] = map[3][i][2];
        for (int i = 0; i < 3; i++) map[3][i][2] = map[2][i][2];
        for (int i = 0; i < 3; i++) map[2][i][2] = map[1][i][2];
        for (int i = 0; i < 3; i++) map[1][i][2] = tmp[i];
        protate(5);
    }

    private static void fminus() {
        for (int i = 0; i < 3; i++) tmp[i] = map[3][0][i];
        for (int i = 0; i < 3; i++) map[3][0][i] = map[5][0][i];
        for (int i = 0; i < 3; i++) map[5][0][i] = map[1][2][2 - i];
        for (int i = 0; i < 3; i++) map[1][2][2 - i] = map[0][0][i];
        for (int i = 0; i < 3; i++) map[0][0][i] = tmp[i];
        protate(4);
    }

    private static void bminus() {
        for (int i = 0; i < 3; i++) tmp[i] = map[3][2][2 - i];
        for (int i = 0; i < 3; i++) map[3][2][2 - i] = map[0][2][2 - i];
        for (int i = 0; i < 3; i++) map[0][2][2 - i] = map[1][0][i];
        for (int i = 0; i < 3; i++) map[1][0][i] = map[5][2][2 - i];
        for (int i = 0; i < 3; i++) map[5][2][2 - i] = tmp[i];
        protate(2);
    }

    private static void protate(int t) {
        for (int i = 0; i < 2; i++) tmp[i] = map[t][2][i];
        for (int i = 0; i < 2; i++) map[t][2][i] = map[t][2 - i][2];
        for (int i = 0; i < 2; i++) map[t][2 - i][2] = map[t][0][2 - i];
        for (int i = 0; i < 2; i++) map[t][0][2 - i] = map[t][i][0];
        for (int i = 0; i < 2; i++) map[t][i][0] = tmp[i];
    }
}
