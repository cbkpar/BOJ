import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int iH = Integer.parseInt(st.nextToken());
        int iW = Integer.parseInt(st.nextToken());
        int iC = Integer.parseInt(st.nextToken());
        int[] arrCount = new int[iC + 1];
        int[][] mapNumber = new int[iH][iW];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= iC; ++i) {
            arrCount[i] = Integer.parseInt(st.nextToken());
        }
        int iCount = 0;
        for (int i = 1; i <= iC; ++i) {
            while (arrCount[i]-- > 0) {
                mapNumber[iCount / iW][iCount % iW] = i;
                ++iCount;
            }
        }
        for (int i = 0; i < iH; ++i) {
            for (int j = 0; j < iW; ++j) {
                if (i % 2 == 0) {
                    sb.append(mapNumber[i][j]);
                } else {
                    sb.append(mapNumber[i][iW - j - 1]);
                }

            }
            sb.append("\n");
        }
        System.out.println(sb);
    }
}
