import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int iN = Integer.parseInt(br.readLine());
        boolean[] bIsVisited = new boolean[15001];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < iN; ++i) {
            int iK = Integer.parseInt(st.nextToken());
            bIsVisited[iK] = true;
        }
        int iSum = 15000;
        for (int i = 1; i <= 15000; ++i) {
            if (bIsVisited[i]) {
                --iSum;
            }
        }
        System.out.println(iSum);
    }
}
