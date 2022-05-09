import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        int[] iTree = InputData();
        System.out.println(Solve(iTree));
    }

    private static int[] InputData() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int iN = Integer.parseInt(br.readLine());
        int[] iTree = new int[iN];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < iN; ++i) {
            iTree[i] = Integer.parseInt(st.nextToken());
        }
        return iTree;
    }

    private static String Solve(int[] _iTree) {
        int iOdd = 0;
        int iEven = 0;
        int iSize = _iTree.length;
        for (int i = 0; i < iSize; ++i) {
            iOdd += _iTree[i] % 2;
            iEven += _iTree[i] / 2;
        }
        if (iOdd > iEven || (iOdd - iEven) % 3 != 0) return "NO";
        return "YES";
    }
}
