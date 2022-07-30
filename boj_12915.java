import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int iE = Integer.parseInt(st.nextToken());
        int iEM = Integer.parseInt(st.nextToken());
        int iM = Integer.parseInt(st.nextToken());
        int iMH = Integer.parseInt(st.nextToken());
        int iH = Integer.parseInt(st.nextToken());
        int iAns = 0;
        while (true) {
            if (iE > 0 && iM > 0 && iH > 0) {
                --iE;
                --iM;
                --iH;
                ++iAns;
                continue;
            }
            if (iE == 0 && iEM > 0) {
                ++iE;
                --iEM;
                continue;
            }
            if (iH == 0 && iMH > 0) {
                ++iH;
                --iMH;
                continue;
            }
            if (iM == 0 && iEM > 0 && iEM >= iMH) {
                ++iM;
                --iEM;
                continue;
            }
            if (iM == 0 && iMH > 0  && iMH >= iEM) {
                ++iM;
                --iMH;
                continue;
            }
            break;
        }
        System.out.println(iAns);
    }
}
