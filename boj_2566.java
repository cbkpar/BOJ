import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int iMax = -1;
        int iPosX = -1;
        int iPosY = -1;
        for (int i = 1; i <= 9; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= 9; ++j) {
                int iN = Integer.parseInt(st.nextToken());
                if (iN > iMax) {
                    iMax = iN;
                    iPosY = i;
                    iPosX = j;
                }
            }
        }
        System.out.println(iMax + "\n" + iPosY + " " + iPosX);
    }
}
