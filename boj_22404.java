import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int iN = Integer.parseInt(st.nextToken());
        int iM = Integer.parseInt(st.nextToken());
        int iT = Integer.parseInt(st.nextToken());
        int[] ArrTime = new int[iT + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < iN; ++i) {
            int iTime = Integer.parseInt(st.nextToken());
            ++ArrTime[(iTime - iM < 0 ? 0 : iTime - iM)];
            --ArrTime[(iTime + iM >= iT ? iT : iTime + iM)];
        }
        for (int i = 1; i < iT; ++i) {
            ArrTime[i] += ArrTime[i - 1];
        }
        int iCount = 0;
        for (int i = 0; i < iT; ++i) {
            if (0 == ArrTime[i]) {
                ++iCount;
            }
        }
        System.out.println(iCount);
    }
}
