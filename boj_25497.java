import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int iN = Integer.parseInt(br.readLine());
        String str = br.readLine();
        int iCount = 0;
        int iL = 0;
        int iS = 0;
        for (int i = 0; i < iN; ++i) {
            if (str.charAt(i) == 'L') {
                ++iL;
            } else if (str.charAt(i) == 'R') {
                if (iL == 0) {
                    break;
                }
                --iL;
                ++iCount;
            } else if (str.charAt(i) == 'S') {
                ++iS;
            } else if (str.charAt(i) == 'K') {
                if (iS == 0) {
                    break;
                }
                --iS;
                ++iCount;
            } else {
                ++iCount;
            }
        }
        System.out.println(iCount);
    }
}
