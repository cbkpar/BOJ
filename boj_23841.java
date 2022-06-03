import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int iN = Integer.parseInt(st.nextToken());
        int iM = Integer.parseInt(st.nextToken());
        for (int i = 0; i < iN; ++i) {
            char[] arrCh = br.readLine().toCharArray();
            for (int j = 0; j < iM; ++j) {
                if ('.' != arrCh[j]) {
                    arrCh[iM - j - 1] = arrCh[j];
                }
            }
            System.out.println(arrCh);
        }
    }
}
