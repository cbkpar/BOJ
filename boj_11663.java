import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int iN = Integer.parseInt(st.nextToken());
        int iM = Integer.parseInt(st.nextToken());
        int[] arrNmber = new int[iN];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < iN; ++i) {
            arrNmber[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arrNmber);
        while (iM-- > 0) {
            st = new StringTokenizer(br.readLine());
            int iS = Integer.parseInt(st.nextToken());
            int iE = Integer.parseInt(st.nextToken());
            int iCount = 0;
            {
                int iLeft = 0;
                int iRight = iN;
                while (iLeft < iRight) {
                    int iMid = (iLeft + iRight) / 2;
                    if (arrNmber[iMid] >= iS) {
                        iRight = iMid;
                    } else {
                        iLeft = iMid + 1;
                    }
                }
                iCount -= iRight;
            }
            {
                int iLeft = 0;
                int iRight = iN;
                while (iLeft < iRight) {
                    int iMid = (iLeft + iRight) / 2;
                    if (arrNmber[iMid] >= iE + 1) {
                        iRight = iMid;
                    } else {
                        iLeft = iMid + 1;
                    }
                }
                iCount += iRight;
            }
            sb.append(iCount + "\n");
        }
        System.out.println(sb);
    }
}
