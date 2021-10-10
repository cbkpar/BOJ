import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            long[][] pos = new long[4][2];
            for (int i = 0; i < 4; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                pos[i][0] = Integer.parseInt(st.nextToken());
                pos[i][1] = Integer.parseInt(st.nextToken());
            }
            boolean chk = false;
            long a = (long) Math.pow(pos[0][0] - pos[2][0], 2) + (long) Math.pow(pos[0][1] - pos[2][1], 2);
            long b = (long) Math.pow(pos[0][0] - pos[3][0], 2) + (long) Math.pow(pos[0][1] - pos[3][1], 2);
            long c = (long) Math.pow(pos[1][0] - pos[2][0], 2) + (long) Math.pow(pos[1][1] - pos[2][1], 2);
            long d = (long) Math.pow(pos[1][0] - pos[3][0], 2) + (long) Math.pow(pos[1][1] - pos[3][1], 2);
            long e = (long) Math.pow(pos[2][0] - pos[3][0], 2) + (long) Math.pow(pos[2][1] - pos[3][1], 2);
            if (a == b && b == c && c == d && (a + b) == e) chk = true;

            a = (long) Math.pow(pos[0][0] - pos[1][0], 2) + (long) Math.pow(pos[0][1] - pos[1][1], 2);
            b = (long) Math.pow(pos[0][0] - pos[3][0], 2) + (long) Math.pow(pos[0][1] - pos[3][1], 2);
            c = (long) Math.pow(pos[2][0] - pos[1][0], 2) + (long) Math.pow(pos[2][1] - pos[1][1], 2);
            d = (long) Math.pow(pos[2][0] - pos[3][0], 2) + (long) Math.pow(pos[2][1] - pos[3][1], 2);
            e = (long) Math.pow(pos[1][0] - pos[3][0], 2) + (long) Math.pow(pos[1][1] - pos[3][1], 2);
            if (a == b && b == c && c == d && (a + b) == e) chk = true;

            a = (long) Math.pow(pos[0][0] - pos[1][0], 2) + (long) Math.pow(pos[0][1] - pos[1][1], 2);
            b = (long) Math.pow(pos[0][0] - pos[2][0], 2) + (long) Math.pow(pos[0][1] - pos[2][1], 2);
            c = (long) Math.pow(pos[3][0] - pos[1][0], 2) + (long) Math.pow(pos[3][1] - pos[1][1], 2);
            d = (long) Math.pow(pos[3][0] - pos[2][0], 2) + (long) Math.pow(pos[3][1] - pos[2][1], 2);
            e = (long) Math.pow(pos[1][0] - pos[2][0], 2) + (long) Math.pow(pos[1][1] - pos[2][1], 2);
            if (a == b && b == c && c == d && (a + b) == e) chk = true;
            sb.append(chk ? "1\n" : "0\n");
        }
        System.out.println(sb);
    }
}
