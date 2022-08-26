import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int iN = Integer.parseInt(br.readLine());
        long lAns = 0;
        long[] lArrNumber = new long[iN];
        for (int i = 0; i < iN; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            lArrNumber[i] = Long.parseLong(st.nextToken());
            lAns += Long.parseLong(st.nextToken());
        }
        Arrays.sort(lArrNumber);
        for (int i = 0; i < iN; ++i) {
            lAns += lArrNumber[i] * (i + 1);
        }
        System.out.println(lAns);
    }
}
