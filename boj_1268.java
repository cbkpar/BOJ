import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, i, j, k, mx, t, num;
        n = Integer.parseInt(br.readLine());
        int[][] arr = new int[n][5];
        for (i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (j = 0; j < 5; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        mx = -1;
        num = 0;
        for (i = 0; i < n; i++) {
            t = 0;
            for (j = 0; j < n; j++) {
                if (i == j) continue;
                for (k = 0; k < 5; k++) {
                    if (arr[i][k] == arr[j][k]){
                        t++;
                        break;
                    }
                }
            }
            if (t > mx) {
                mx = t;
                num = i + 1;
            }
        }
        System.out.println(num);
    }
}
