import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int iN = Integer.parseInt(st.nextToken());
        int iK = Integer.parseInt(st.nextToken());
        int[] arrColor = new int[iN];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < iN; ++i) {
            arrColor[i] = Integer.parseInt(st.nextToken());
        }
        int iAnswer = 1;
        int iCount = 1;
        for (int i = 1; i < iN; ++i) {
            if (arrColor[i] != arrColor[i - 1]) {
                ++iCount;
                iAnswer = Math.max(iAnswer, iCount);
            } else {
                iCount = 1;
            }
        }
        System.out.println(iAnswer);
    }
}
