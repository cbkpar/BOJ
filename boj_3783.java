import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.math.MathContext;
import java.math.RoundingMode;

public class Main {

    public static BigDecimal cuberoot(BigDecimal b, MathContext mc) {
        BigDecimal x = new BigDecimal("1.0");
        for (int i = 0; i < 1000; i++) {
            BigDecimal Nextx = x.subtract(x.pow(3, mc).subtract(b, mc).divide(new BigDecimal("3.0", mc).multiply(x.pow(2, mc), mc), mc), mc);
            if (x.compareTo(Nextx) == 0) break;
            x = Nextx;
        }
        return x;
    }

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        MathContext mc = new MathContext(170);

        int iT = Integer.parseInt(br.readLine());
        while (iT-- > 0) {
            String strNum = br.readLine();
            BigDecimal bigNum = new BigDecimal(strNum, mc);
            BigDecimal bigAns = cuberoot(bigNum, mc);
            System.out.println(bigAns.setScale(10, RoundingMode.FLOOR).toString());
        }
    }
}
