import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int iN = Integer.parseInt(st.nextToken());
        int iM = Integer.parseInt(st.nextToken());
        String[] arrString = new String[iN + 1];
        int[] arrCount = new int[iN + 1];
        arrCount[0] = -1;
        for (int i = 1; i <= iN; ++i) {
            st = new StringTokenizer(br.readLine());
            arrString[i] = st.nextToken();
            arrCount[i] = Integer.parseInt(st.nextToken());
        }
        while (iM-- > 0) {
            int iPower = Integer.parseInt(br.readLine());
            int iLeft = 0;
            int iRight = iN;
            int iAns = 0;
            while (iLeft <= iRight) {
                int iMid = (iLeft + iRight) / 2;
                if (iPower > arrCount[iMid]) {
                    iAns = iMid + 1;
                    iLeft = iMid + 1;
                } else {
                    iRight = iMid - 1;
                }
            }
            sb.append(arrString[iAns] + "\n");
        }
        System.out.println(sb);
    }
}
