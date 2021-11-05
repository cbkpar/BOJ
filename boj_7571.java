import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] Arrx = new int[m];
        int[] Arry = new int[m];
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            Arrx[i] = x;
            Arry[i] = y;
        }
        Arrays.sort(Arrx);
        Arrays.sort(Arry);
        int sx = (Arrx[(m - 1) - m / 2] + Arrx[(m) / 2]) / 2;
        int sy = (Arry[(m - 1) - m / 2] + Arry[(m) / 2]) / 2;
        long tx = 0;
        long ty = 0;
        for (int i = 0; i < m; i++) {
            tx += Math.abs(sx - Arrx[i]);
            ty += Math.abs(sy - Arry[i]);
        }
        System.out.println(tx + ty);
    }
}
