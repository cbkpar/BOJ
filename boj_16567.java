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
        boolean[] ArrIsDirty = new boolean[iN + 2];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= iN; ++i) {
            if ('1' == st.nextToken().charAt(0)) {
                ArrIsDirty[i] = true;
            }
        }
        int iCount = 0;
        for (int i = 1; i <= iN; ++i) {
            if (!ArrIsDirty[i - 1] && ArrIsDirty[i]) {
                ++iCount;
            }
        }
        while (iM-- > 0) {
            st = new StringTokenizer(br.readLine());
            if ('0' == st.nextToken().charAt(0)) {
                sb.append(iCount + "\n");
            } else {
                int iNum = Integer.parseInt(st.nextToken());
                if (!ArrIsDirty[iNum]) {
                    if (ArrIsDirty[iNum - 1]) {
                        --iCount;
                    }
                    if (ArrIsDirty[iNum + 1]) {
                        --iCount;
                    }
                    ArrIsDirty[iNum] = true;
                    ++iCount;
                }
            }
        }
        System.out.println(sb);
    }
}
