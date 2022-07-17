import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int iN = Integer.parseInt(st.nextToken());
        int iK = Integer.parseInt(st.nextToken());
        int[] ArrHeight = new int[iN];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < iN; ++i) {
            ArrHeight[i] = Integer.parseInt(st.nextToken());
        }
        ArrayList<Integer> ArrDiff = new ArrayList<>();
        for (int i = 1; i < iN; ++i) {
            ArrDiff.add(ArrHeight[i] - ArrHeight[i - 1]);
        }
        Collections.sort(ArrDiff);
        int iSum = 0;
        for (int i = 0; i < iN - iK; ++i) {
            iSum += ArrDiff.get(i);
        }
        System.out.println(iSum);
    }
}
