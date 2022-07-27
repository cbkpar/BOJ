import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int iN = Integer.parseInt(st.nextToken());
        int iM = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        double dA = Double.parseDouble(st.nextToken());
        double dB = Double.parseDouble(st.nextToken());
        double dC = Double.parseDouble(st.nextToken());
        double dD = Double.parseDouble(st.nextToken());
        double[][] dRatio = new double[iN + 1][2];
        if (iM == 0) {
            dRatio[0][0] = 1;
        } else {
            dRatio[0][1] = 1;
        }
        for (int i = 1; i <= iN; ++i) {
            dRatio[i][0] = dRatio[i - 1][0] * dA + dRatio[i - 1][1] * dC;
            dRatio[i][1] = dRatio[i - 1][0] * dB + dRatio[i - 1][1] * dD;
        }
        System.out.println((int) (dRatio[iN][0] * 1000) + "\n" + (int) (dRatio[iN][1] * 1000));
    }
}
