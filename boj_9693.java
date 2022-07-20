import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int iCase = 0;
        while (true) {
            int iN = Integer.parseInt(br.readLine());
            if (0 == iN) {
                break;
            }
            int iM = 0;
            while (iN > 0) {
                iN /= 5;
                iM += iN;
            }
            sb.append("Case #" + (++iCase) + ": " + iM + "\n");
        }
        System.out.println(sb);
    }
}
