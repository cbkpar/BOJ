import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int iN = Integer.parseInt(br.readLine());
        int[] arrSpeed = new int[iN];
        for (int i = 0; i < iN; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            st.nextToken();
            arrSpeed[i] = Integer.parseInt(st.nextToken());
        }
        int iCount = 0;
        int iMinSpeed = Integer.MAX_VALUE;
        for (int i = iN - 1; i >= 0; --i) {
            if (arrSpeed[i] <= iMinSpeed) {
                iMinSpeed = arrSpeed[i];
                ++iCount;
            }
        }
        System.out.println(iCount);
    }
}
