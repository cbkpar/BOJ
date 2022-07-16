import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int iN = Integer.parseInt(br.readLine());
        long[] ArrPresum = new long[iN + 1];
        long[] ArrNumber = new long[iN];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < iN; ++i) {
            ArrNumber[i] = Long.parseLong(st.nextToken());
        }
        for (int i = iN - 1; i >= 0; --i) {
            ArrPresum[i] = (ArrNumber[i] + ArrPresum[i + 1]) % 1000000007;
        }
        long lSum = 0;
        for (int i = 0; i < iN - 1; ++i) {
            lSum = (lSum + ArrNumber[i] * ArrPresum[i + 1]) % 1000000007;
        }
        System.out.println(lSum);
    }
}
