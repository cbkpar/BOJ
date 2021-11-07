import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int[] dy = {-1, 0, 1, 0};
        int[] dx = {0, 1, 0, -1};
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String str = br.readLine();
            int sz = str.length();
            int ny = 0;
            int nx = 0;
            int dir = 0;
            int minX = 0;
            int maxX = 0;
            int minY = 0;
            int maxY = 0;
            for (int i = 0; i < sz; i++) {
                if (str.charAt(i) == 'F') {
                    ny += dy[dir];
                    nx += dx[dir];
                } else if (str.charAt(i) == 'B') {
                    ny -= dy[dir];
                    nx -= dx[dir];
                } else if (str.charAt(i) == 'L') {
                    dir = (dir + 3) % 4;
                } else {
                    dir = (dir + 1) % 4;
                }
                minX = Math.min(minX, nx);
                maxX = Math.max(maxX, nx);
                minY = Math.min(minY, ny);
                maxY = Math.max(maxY, ny);
            }
            sb.append((maxX - minX) * (maxY - minY) + "\n");
        }
        System.out.println(sb);
    }
}
