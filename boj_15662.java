import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int[][] gear;
    static int n;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int k, i, j, num, rotate, cnt;
        n = Integer.parseInt(br.readLine());
        gear = new int[n][8];
        for (i = 0; i < n; i++) {
            String str = br.readLine();
            for (j = 0; j < 8; j++) gear[i][j] = str.charAt(j) - '0';
        }
        k = Integer.parseInt(br.readLine());
        while (k-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            num = Integer.parseInt(st.nextToken()) - 1;
            rotate = Integer.parseInt(st.nextToken());
            rootcheck(num, rotate);
        }
        cnt = 0;
        for (i = 0; i < n; i++) cnt += gear[i][0];
        System.out.println(cnt);
    }

    public static void rootcheck(int num, int rotate) {
        if (num != 0) if (gear[num - 1][2] != gear[num][6]) lcheck(num - 1, rotate * -1);
        if (num != n - 1) if (gear[num + 1][6] != gear[num][2]) rcheck(num + 1, rotate * -1);
        rotate(num, rotate);
    }

    public static void lcheck(int num, int rotate) {
        if (num != 0) if (gear[num - 1][2] != gear[num][6]) lcheck(num - 1, rotate * -1);
        rotate(num, rotate);
    }

    public static void rcheck(int num, int rotate) {
        if (num != n - 1) if (gear[num + 1][6] != gear[num][2]) rcheck(num + 1, rotate * -1);
        rotate(num, rotate);
    }

    public static void rotate(int num, int rotate) {
        if (rotate == 1) {
            int t = gear[num][7];
            for (int i = 7; i > 0; i--) gear[num][i] = gear[num][i - 1];
            gear[num][0] = t;
        } else {
            int t = gear[num][0];
            for (int i = 0; i < 7; i++) gear[num][i] = gear[num][i + 1];
            gear[num][7] = t;
        }
    }
}
