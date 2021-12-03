import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long x1 = Integer.parseInt(st.nextToken());
        long y1 = Integer.parseInt(st.nextToken());
        long x2 = Integer.parseInt(st.nextToken());
        long y2 = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        long x3 = Integer.parseInt(st.nextToken());
        long y3 = Integer.parseInt(st.nextToken());
        long x4 = Integer.parseInt(st.nextToken());
        long y4 = Integer.parseInt(st.nextToken());
        if (CCW(x1, y1, x2, y2, x3, y3) * CCW(x1, y1, x2, y2, x4, y4) > 0) {
            System.out.println("0");
            return;
        }
        if (CCW(x3, y3, x4, y4, x1, y1) * CCW(x3, y3, x4, y4, x2, y2) > 0) {
            System.out.println("0");
            return;
        }
        System.out.println("1");
    }

    private static long CCW(long x1, long y1, long x2, long y2, long x3, long y3) {
        long tmp = x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2;
        if (tmp > 0) return 1;
        if (tmp == 0) return 0;
        return -1;
    }
}
