import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[][][] block = {
                {{0}, {0, 0, 0, 0}},
                {{0, 0}},
                {{0, 0, -1}, {-1, 0}},
                {{-1, 0, 0}, {0, -1}},
                {{0, 0, 0}, {-1, 0}, {0, -1}, {-1, 0, -1}},
                {{0, 0, 0}, {0, 0}, {0, -1, -1}, {-2, 0}},
                {{0, 0, 0}, {0, 0}, {-1, -1, 0}, {0, -2}}};
        StringTokenizer st = new StringTokenizer(br.readLine());
        int c = Integer.parseInt(st.nextToken());
        int p = Integer.parseInt(st.nextToken()) - 1;
        int cnt = 0;
        int[] height = new int[c];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < c; i++) height[i] = Integer.parseInt(st.nextToken());
        int sz = block[p].length;
        for (int i = 0; i < sz; i++) {
            int bsz = block[p][i].length;
            for (int j = 0; j <= c - bsz; j++) {
                boolean chk = true;
                for (int k = 1; k < bsz; k++) {
                    if (height[j + k - 1] + block[p][i][k - 1] != height[j + k] + block[p][i][k]) {
                        chk = false;
                        break;
                    }
                }
                if (chk) cnt++;
            }
        }
        System.out.println(cnt);
    }
}
