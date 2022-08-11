import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int iT = Integer.parseInt(br.readLine());
        while (iT-- > 0) {
            br.readLine();
            StringTokenizer st = new StringTokenizer(br.readLine());
            int iN = Integer.parseInt(st.nextToken());
            int iM = Integer.parseInt(st.nextToken());
            String[] arrString = new String[iN];
            for (int i = 0; i < iN; ++i) {
                arrString[i] = br.readLine();
            }
            int iCount = 0;
            for (int i = 0; i < iN - 2; ++i) {
                for (int j = 0; j < iM; ++j) {
                    if (arrString[i].charAt(j) == 'v' && arrString[i + 1].charAt(j) == 'o' && arrString[i + 2].charAt(j) == '^') {
                        ++iCount;
                    }
                }
            }
            for (int i = 0; i < iN; ++i) {
                for (int j = 0; j < iM - 2; ++j) {
                    if (arrString[i].charAt(j) == '>' && arrString[i].charAt(j + 1) == 'o' && arrString[i].charAt(j + 2) == '<') {
                        ++iCount;
                    }
                }
            }
            sb.append(iCount + "\n");
        }
        System.out.println(sb);
    }
}
