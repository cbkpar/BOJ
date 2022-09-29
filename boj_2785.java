import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int iN = Integer.parseInt(br.readLine());
        int[] arrLength = new int[iN];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < iN; ++i) {
            arrLength[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arrLength);
        int iCount = 0;
        int iLeft = 0;
        int iRight = iN - 1;
        while (iLeft < iRight) {
            ++iCount;
            --arrLength[iLeft];
            if (arrLength[iLeft] == 0) {
                ++iLeft;
            }
            --iRight;
        }
        System.out.println(iCount);
    }
}
