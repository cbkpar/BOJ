import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int iN = Integer.parseInt(br.readLine());
        int iMax = 0;
        for (int i = 0; i < iN; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int iA = Integer.parseInt(st.nextToken());
            int iD = Integer.parseInt(st.nextToken());
            int iG = Integer.parseInt(st.nextToken());
            if (iA == iD + iG) {
                iMax = Math.max(iMax, iA * (iD + iG) * 2);
            } else {
                iMax = Math.max(iMax, iA * (iD + iG));
            }
        }
        System.out.println(iMax);
    }
}
