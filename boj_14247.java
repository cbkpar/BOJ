import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int iN = Integer.parseInt(br.readLine());
        long lSum = 0;
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < iN; ++i) {
            lSum += Integer.parseInt(st.nextToken());
        }
        int[] arrHeight = new int[iN];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < iN; ++i) {
            arrHeight[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arrHeight);
        for (int i = 0; i < iN; ++i) {
            lSum += arrHeight[i] * i;
        }
        System.out.println(lSum);
    }
}
