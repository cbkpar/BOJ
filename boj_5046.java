import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int iN = Integer.parseInt(st.nextToken());
        int iB = Integer.parseInt(st.nextToken());
        int iH = Integer.parseInt(st.nextToken());
        int iW = Integer.parseInt(st.nextToken());
        int iMinCost = Integer.MAX_VALUE;
        for (int i = 0; i < iH; ++i) {
            int iCost = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < iW; ++j) {
                int iCount = Integer.parseInt(st.nextToken());
                int iTotalCost = iCost * iN;
                if (iCount >= iN && iTotalCost <= iB) {
                    iMinCost = Math.min(iMinCost, iTotalCost);
                }
            }
        }
        System.out.println((iMinCost == Integer.MAX_VALUE ? "stay home" : iMinCost));
    }
}
