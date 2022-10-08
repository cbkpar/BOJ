import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int iN = Integer.parseInt(br.readLine());
        boolean[] arrCake = new boolean[iN + 1];
        int iPeople = Integer.parseInt(br.readLine());
        int iIdealMax = -1;
        int iIdealIndex = -1;
        int iRealMax = -1;
        int iRealIndex = -1;
        for (int i = 1; i <= iPeople; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int iS = Integer.parseInt(st.nextToken());
            int iE = Integer.parseInt(st.nextToken());
            if (iE - iS + 1 > iIdealMax) {
                iIdealMax = iE - iS + 1;
                iIdealIndex = i;
            }
            int iCount = 0;
            for (int j = iS; j <= iE; ++j) {
                if (!arrCake[j]) {
                    arrCake[j] = true;
                    ++iCount;
                }
            }
            if (iCount > iRealMax) {
                iRealMax = iCount;
                iRealIndex = i;
            }
        }
        System.out.println(iIdealIndex + "\n" + iRealIndex);
    }
}
