import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t, a, b, i, j, area;
        t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            int[][] height = new int[a + 2][b + 2];
            for (i = 1; i <= a; i++) {
                String str = br.readLine();
                for (j = 1; j <= b; j++) {
                    height[i][j] = str.charAt(j - 1) - '0';
                }
            }
            area = 0;
            for (i = 1; i <= a; i++) {
                for (j = 1; j <= b; j++) {
                    if (height[i][j] == 0) continue;
                    area += height[i][j] * 4 + 2;
                    area -= Math.min(height[i][j], height[i - 1][j]);
                    area -= Math.min(height[i][j], height[i + 1][j]);
                    area -= Math.min(height[i][j], height[i][j - 1]);
                    area -= Math.min(height[i][j], height[i][j + 1]);
                }
            }
            sb.append(area + "\n");
        }
        System.out.println(sb);
    }
}
