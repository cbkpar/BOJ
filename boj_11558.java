import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int iT = Integer.parseInt(br.readLine());
        while (iT-- > 0) {
            int iN = Integer.parseInt(br.readLine());
            int[] arrSelect = new int[iN + 1];
            boolean[] Visited = new boolean[iN + 1];
            for (int i = 1; i <= iN; ++i) {
                arrSelect[i] = Integer.parseInt(br.readLine());
            }
            int iNumber = arrSelect[1];
            int iCount = 1;
            Visited[1] = true;
            while (true) {
                if (iNumber == iN) {
                    break;
                }
                if (Visited[arrSelect[iNumber]]) {
                    break;
                }
                ++iCount;
                iNumber = arrSelect[iNumber];
                Visited[iNumber] = true;
            }
            if (iNumber == iN) {
                sb.append(iCount+"\n");
            } else {
                sb.append("0\n");
            }
        }
        System.out.println(sb);
    }
}
