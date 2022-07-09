import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int iN = Integer.parseInt(br.readLine());
        int[] arrNumber = new int[iN];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < iN; ++i) {
            arrNumber[i] = Integer.parseInt(st.nextToken());
        }
        boolean bCheck = true;
        for (int i = 0; i < iN; ++i) {
            for (int j = 0; j < iN; ++j) {
                for (int k = 0; k < iN; ++k) {
                    if (i == j || j == k || k == i) {
                        continue;
                    }
                    if (0 != (arrNumber[i] - arrNumber[j]) % arrNumber[k]) {
                        bCheck = false;
                    }
                }
            }
        }
        System.out.println(bCheck ? "yes" : "no");
    }
}
