import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int iT = Integer.parseInt(br.readLine());
        while (iT-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int iM = Integer.parseInt(st.nextToken());
            int iN = Integer.parseInt(st.nextToken());

            BigInteger[] bArr = new BigInteger[iM];
            for (int i = 0; i < iM; ++i) {
                bArr[i] = new BigInteger("1");
            }
            for (int i = 0; i < iN; ++i) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < iM; ++j) {
                    BigInteger bNumber = new BigInteger(st.nextToken());
                    bArr[j] = bArr[j].multiply(bNumber);
                }
            }
            int iIndex = 0;
            for (int i = 1; i < iM; ++i) {
                if (bArr[i].compareTo(bArr[iIndex]) >= 0) {
                    iIndex = i;
                }
            }
            sb.append((iIndex + 1) + "\n");
        }
        System.out.println(sb);
    }
}
