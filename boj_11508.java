import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int iN = Integer.parseInt(br.readLine());
        int[] arrCost = new int[iN];
        long lAns = 0;
        for (int i = 0; i < iN; ++i) {
            arrCost[i] = Integer.parseInt(br.readLine());
            lAns += arrCost[i];
        }
        Arrays.sort(arrCost);
        for (int i = iN - 3; i >= 0; i -= 3) {
            lAns -= arrCost[i];
        }
        System.out.println(lAns);
    }
}
