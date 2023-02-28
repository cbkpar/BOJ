import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int iMax = -9999;
        int iMin = 9999;

        String str;
        while ((str = br.readLine()) != null) {
            StringTokenizer st = new StringTokenizer(str);
            st.nextToken();
            while (st.hasMoreTokens()) {
                int iNum = Integer.parseInt(st.nextToken());
                iMax = Math.max(iMax, iNum);
                iMin = Math.min(iMin, iNum);
            }
        }
        System.out.println(iMin + " " + iMax);
    }
}
