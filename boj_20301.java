import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int iN = Integer.parseInt(st.nextToken());
        int iK = Integer.parseInt(st.nextToken());
        int iM = Integer.parseInt(st.nextToken());
        ArrayList<Integer> arrNumber = new ArrayList<>();
        for (int i = 1; i <= iN; ++i) {
            arrNumber.add(i);
        }
        int iNow = -1;
        for (int i = 0; i < iN; ++i) {
            if (i % (2 * iM) < iM) {
                iNow = (iNow + iK) % arrNumber.size();
            } else {
                iNow = (iNow - iK + 1) % arrNumber.size();
                if (iNow < 0) {
                    iNow += arrNumber.size();
                }
            }
            sb.append(arrNumber.get(iNow) + "\n");
            arrNumber.remove(iNow--);
        }
        System.out.println(sb);
    }
}
