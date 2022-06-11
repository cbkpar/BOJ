import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] iSize = new int[8];
        for (int i = 0; i < 8; ++i) {
            iSize[i] = Integer.parseInt(br.readLine());
        }
        int iMax = 0;
        for (int i = 0; i < 8; ++i) {
            int iSum = 0;
            for (int j = 0; j < 4; ++j) {
                iSum += iSize[(i + j) % 8];
            }
            iMax = Math.max(iMax, iSum);
        }
        System.out.println(iMax);
    }
}
