import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int iN = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int iX1 = Integer.parseInt(st.nextToken());
        int iY1 = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int iX2 = Integer.parseInt(st.nextToken());
        int iY2 = Integer.parseInt(st.nextToken());
        int iHalf = 0;
        int iRest = 0;
        for (int i = 0; i < iN; ++i) {
            int iAmount = Integer.parseInt(br.readLine());
            if (1 == iAmount % 2) {
                ++iRest;
            }
            iHalf += iAmount / 2;
        }
        for (int i = 0; i <= iRest; ++i) {
            if (iX1 <= iHalf + i && iY1 >= iHalf + i && iX2 <= iHalf + iRest - i && iY2 >= iHalf + iRest - i) {
                System.out.println("Yes");
                return;
            }
        }
        System.out.println("No");
    }
}
