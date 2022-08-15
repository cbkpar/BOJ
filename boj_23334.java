import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int iN = Integer.parseInt(br.readLine());
        long lMax = Long.MIN_VALUE;
        String strName = "";
        while (iN-- > 0) {
            long lTemp = 0;
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < 3; ++i) {
                lTemp *= 1000;
                lTemp += Long.parseLong(st.nextToken());
            }
            if (lTemp > lMax) {
                String strCountryName = st.nextToken();
                while (st.hasMoreTokens()) {
                    strCountryName += " " + st.nextToken();
                }
                strName = strCountryName;
                lMax = lTemp;
            }
        }
        System.out.println(strName);
    }
}
