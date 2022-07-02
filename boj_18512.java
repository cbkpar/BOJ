import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int iX = Integer.parseInt(st.nextToken());
        int iY = Integer.parseInt(st.nextToken());
        int iP1 = Integer.parseInt(st.nextToken());
        int iP2 = Integer.parseInt(st.nextToken());
        if (iX == iY) {
            if (0 == (iP1 - iP2) % iX) {
                System.out.println(Math.max(iP1, iP2));
                return;
            } else {
                System.out.println("-1");
                return;
            }
        } else {
            if (iP1 > iP2) {
                int iTemp = (iP1 - iP2) / iY + (0 != (iP1 - iP2) % iY ? 1 : 0);
                iP2 += iTemp * iY;
            } else {
                int iTemp = (iP2 - iP1) / iX + (0 != (iP2 - iP1) % iX ? 1 : 0);
                iP1 += iTemp * iX;
            }
            for (int i = 0; i < iX; ++i) {
                if (0 == (iP2 - iP1) % iX) {
                    System.out.println(iP2);
                    return;
                }
                iP2 += iY;
            }
            System.out.println("-1");
            return;
        }
    }
}
