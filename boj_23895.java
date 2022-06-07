import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int iT = Integer.parseInt(br.readLine());
        for (int iTest = 1; iTest <= iT; ++iTest) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int iN = Integer.parseInt(st.nextToken());
            int[] arrCost = new int[1001];
            int iB = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < iN; ++i) {
                ++arrCost[Integer.parseInt(st.nextToken())];
            }
            int iCount = 0;
            for (int i = 1; i <= 1000; ++i) {
                if (iB >= arrCost[i] * i) {
                    iCount += arrCost[i];
                    iB -= arrCost[i] * i;
                } else {
                    iCount += iB / i;
                    break;
                }
            }
            sb.append("Case #" + iTest + ": " + iCount + "\n");
        }
        System.out.println(sb);
    }
}
