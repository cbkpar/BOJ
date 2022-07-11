import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int iN;
    static int iAns;
    static int[] arr;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        iN = Integer.parseInt(br.readLine());
        arr = new int[iN];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < iN; ++i) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        iAns = 0;
        dfs(0, 0);
        System.out.println(iAns);
    }

    private static void dfs(int iK, long lDeno) {
        if (iK == iN) {
            if ((lDeno * 100 >= 26771144400L * 99) && (lDeno * 100 <= 26771144400L * 101)) {
                ++iAns;
            }
            return;
        }
        dfs(iK + 1, lDeno + 26771144400L / arr[iK]);
        dfs(iK + 1, lDeno);
    }
}
