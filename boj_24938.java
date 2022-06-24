import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int iN = Integer.parseInt(br.readLine());
        long[] arr = new long[iN];
        StringTokenizer st = new StringTokenizer(br.readLine());
        long lSum = 0;
        for (int i = 0; i < iN; ++i) {
            arr[i] = Integer.parseInt(st.nextToken());
            lSum += arr[i];
        }
        long lKitCount = lSum / iN;
        long lChaos = 0;
        for (int i = 0; i < iN - 1; ++i) {
            arr[i + 1] += arr[i] - lKitCount;
            lChaos += Math.abs(lKitCount - arr[i]);
        }
        System.out.println(lChaos);
    }
}
