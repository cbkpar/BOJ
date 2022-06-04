import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int iN = Integer.parseInt(br.readLine());
        int iAns = iN / 18;
        iN -= iAns * 18;
        iAns *= 2;
        if (0 == iN % 2) {
            if (8 < iN) {
                iAns += 2;
            } else if (0 < iN) {
                iAns += 1;
            }
        } else {
            if (9 < iN) {
                iAns += 3;
            } else if (0 < iN) {
                iAns += 1;
            }
        }
        System.out.println(iAns);
    }
}
