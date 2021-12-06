import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int w = Integer.parseInt(st.nextToken());
        int[][] map = new int[n + 1][2];
        String str = br.readLine();
        int sz = str.length();
        for (int i = 1; i <= sz; i++) {
            if (str.charAt(i - 1) == 'B') {
                map[i][0] = map[i - 1][0] + 1;
                map[i][1] = map[i - 1][1];
            } else {
                map[i][0] = map[i - 1][0];
                map[i][1] = map[i - 1][1] + 1;
            }
        }
        int l = 0;
        int r = b + w;
        int ans = 0;
        while (r <= sz) {
            if ((map[r][0] - map[l][0] <= b) && (map[r][1] - map[l][1] >= w)) {
                ans = r - l;
                r++;
            } else {
                l++;
                r++;
            }
        }
        System.out.println(ans);
    }
}
