import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int iN = Integer.parseInt(st.nextToken());
        int iM = Integer.parseInt(st.nextToken());
        long[] lArr = new long[iM];
        for (int i = 0; i < iM; ++i) lArr[i] = Long.parseLong(br.readLine());
        long lLeft = 1;
        long lRight = Integer.MAX_VALUE;
        long lAns = Integer.MAX_VALUE;
        while (lLeft <= lRight) {
            long lMid = (lLeft + lRight) / 2;
            long lSum = 0;
            for (int i = 0; i < iM; ++i) lSum += lArr[i] / lMid + (lArr[i] % lMid == 0 ? 0 : 1);
            if (lSum > iN) {
                lLeft = lMid + 1;
            } else {
                lAns = Math.min(lAns, lMid);
                lRight = lMid - 1;
            }
        }
        System.out.println(lAns);
    }
}
