import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int iN = Integer.parseInt(br.readLine());
        String strN = br.readLine();
        int iM = Integer.parseInt(br.readLine());
        String strM = br.readLine();
        int iCount = 0;
        int iPos = iN - 1;
        int iAccCount = 0;
        for (int i = 0; i < iM; ++i) {
            while (true) {
                iPos = (iPos + 1) % iN;
                ++iAccCount;
                ++iCount;
                if (iAccCount == iN + 1) {
                    System.out.println("-1");
                    return;
                }
                if (strM.charAt(i) == strN.charAt(iPos)) {
                    iAccCount = 0;
                    break;
                }
            }
        }
        System.out.println(iCount);
    }
}
