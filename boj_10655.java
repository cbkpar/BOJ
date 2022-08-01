import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int iN = Integer.parseInt(br.readLine());
        int[][] map = new int[iN][2];
        for (int i = 0; i < iN; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            map[i][0] = Integer.parseInt(st.nextToken());
            map[i][1] = Integer.parseInt(st.nextToken());
        }
        long lSum = 0;
        for (int i = 1; i < iN; ++i) {
            lSum += Math.abs(map[i][0] - map[i - 1][0]);
            lSum += Math.abs(map[i][1] - map[i - 1][1]);
        }
        long lMax = Integer.MIN_VALUE;
        for (int i = 2; i < iN; ++i) {
            long lTemp = 0;
            lTemp += Math.abs(map[i][0] - map[i - 1][0]) + Math.abs(map[i][1] - map[i - 1][1]);
            lTemp += Math.abs(map[i - 1][0] - map[i - 2][0]) + Math.abs(map[i - 1][1] - map[i - 2][1]);
            lTemp -= Math.abs(map[i][0] - map[i - 2][0]) + Math.abs(map[i][1] - map[i - 2][1]);
            lMax = Math.max(lMax, lTemp);
        }
        System.out.println(lSum - lMax);
    }
}
