import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int iN = Integer.parseInt(br.readLine()) % 100;
        int[] arrN = new int[100];
        int iMax = 5;
        int iNow = 0;
        boolean bIsright = true;
        for (int i = 1; i < 100; ++i) {
            iNow += bIsright ? 1 : -1;
            arrN[i] = (iNow + 4) / 5;
            if (iMax == iNow) {
                iMax += 5;
                bIsright = false;
            }
            if (0 == iNow) {
                bIsright = true;
            }
        }
        System.out.println(arrN[iN]);
    }
}
