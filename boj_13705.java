import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.StringTokenizer;

public class Main {

    static BigDecimal twoPI;

    public static BigDecimal sine(BigDecimal x) {
        x = x.remainder(twoPI);
        BigDecimal pow = x.multiply(x);
        BigDecimal sum = x;
        BigDecimal temp = x;
        for (int i = 1; i <= 1024; ++i) {
            temp = temp.multiply(pow);
            temp = temp.divide(BigDecimal.valueOf(-1.0 * (i * 2) * (i * 2 + 1)), 256, BigDecimal.ROUND_HALF_UP);
            sum = sum.add(temp);
            if (temp.setScale(256, RoundingMode.HALF_UP).compareTo(BigDecimal.ZERO) == 0) break;
        }
        return sum;
    }

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        twoPI = new BigDecimal("3.141592653589793238462643383279502884197169399");
        twoPI = twoPI.multiply(new BigDecimal("2.0"));

        String strA, strB, strC;
        strA = st.nextToken();
        strB = st.nextToken();
        strC = st.nextToken();

        BigDecimal bigA = new BigDecimal(strA);
        BigDecimal bigB = new BigDecimal(strB);
        BigDecimal bigC = new BigDecimal(strC);

        BigDecimal bigLeft = new BigDecimal("0.0");
        BigDecimal bigRight = new BigDecimal("200000.0");
        BigDecimal bigAns = new BigDecimal("0.0");

        BigDecimal bigTwo = new BigDecimal("2.0");
        while (true) {
            if (bigLeft.setScale(6, RoundingMode.HALF_UP).compareTo(bigRight.setScale(6, RoundingMode.HALF_UP)) == 0)
                break;
            BigDecimal bigMid = bigLeft.add(bigRight).divide(bigTwo);
            BigDecimal bigSine = sine(bigMid);
            BigDecimal bigSum = bigA.multiply(bigMid);
            bigSum = bigSum.add(bigB.multiply(bigSine));
            bigSum = bigSum.subtract(bigC);
            if (bigSum.compareTo(BigDecimal.ZERO) == 1) {
                bigRight = bigMid;
            } else if (bigSum.compareTo(BigDecimal.ZERO) == -1) {
                bigLeft = bigMid;
            }
            bigAns = bigMid;
        }
        System.out.println(bigAns.setScale(6, RoundingMode.HALF_UP).toString());
    }
}
