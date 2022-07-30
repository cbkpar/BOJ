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
        boolean[][] bChecked = new boolean[iN][iM];
        for (int i = 0; i < iN; ++i) {
            String str = br.readLine();
            for (int j = 0; j < iM; ++j) {
                if (str.charAt(j) == 'W') {
                    bChecked[i][j] = true;
                }
            }
        }
        br.readLine();
        int iSum = 0;
        for (int i = 0; i < iN; ++i) {
            String str = br.readLine();
            for (int j = 0; j < iM; ++j) {
                if (bChecked[i][j] && str.charAt(j) == 'W') {
                    ++iSum;
                } else if (!bChecked[i][j] && str.charAt(j) == 'B') {
                    ++iSum;
                }
            }
        }
        System.out.println(iSum);
    }
}
