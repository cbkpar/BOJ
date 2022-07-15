import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        long lA = Long.parseLong(st.nextToken());
        long lD = Long.parseLong(st.nextToken());
        int iQuery = Integer.parseInt(br.readLine());
        while (iQuery-- > 0) {
            st = new StringTokenizer(br.readLine());
            int iType = Integer.parseInt(st.nextToken());
            long lLeft = Long.parseLong(st.nextToken());
            long lRight = Long.parseLong(st.nextToken());
            if (1 == iType) {
                long lSum = (lRight - lLeft + 1) * lA + ((lRight) * (lRight - 1) - (lLeft - 1) * (lLeft - 2)) / 2 * lD;
                sb.append(lSum + "\n");
            } else if (2 == iType) {
                if (lLeft == lRight) {
                    sb.append((lA + (lLeft - 1) * lD) + "\n");
                } else {
                    lRight = lA + (lLeft) * lD;
                    lLeft = lA + (lLeft - 1) * lD;
                    sb.append(gcd(lLeft, lRight) + "\n");
                }
            }
        }
        System.out.println(sb);
    }

    private static long gcd(long a, long b) {
        if (a % b == 0) return b;
        return gcd(b, a % b);
    }
}
