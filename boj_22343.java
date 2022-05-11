import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int[] arrA = new int[1500001];
    static int[] arrB = new int[1500001];

    public static void main(String args[]) throws IOException {
        StringBuilder sb = new StringBuilder();
        int iT = Integer.parseInt(br.readLine());
        while (iT-- > 0) {
            ClearArr();
            InputArr(arrA);
            InputArr(arrB);
            sb.append(CompareArr(arrA, arrB) + "\n");
        }
        System.out.println(sb);
    }

    private static void ClearArr() {
        Arrays.fill(arrA, 0);
        Arrays.fill(arrB, 0);
    }

    private static void InputArr(int[] _arr) throws IOException {
        String strInput = br.readLine();
        int iDepth = 0;
        int iLength = strInput.length();
        for (int i = 0; i < iLength; ++i) {
            if ('(' == strInput.charAt(i)) {
                ++iDepth;
            } else {
                if ('(' == strInput.charAt(i - 1)) {
                    ++_arr[iDepth];
                }
                --iDepth;
            }
        }
        for (int i = 0; i < 1500000; ++i) {
            _arr[i + 1] += _arr[i] / 2;
            _arr[i] %= 2;
        }
    }

    private static String CompareArr(int[] _arrA, int[] _arrB) {
        for (int i = 1500000; i >= 0; --i) {
            if (_arrA[i] == _arrB[i]) {
                continue;
            } else if (_arrA[i] > _arrB[i]) {
                return ">";
            } else {
                return "<";
            }
        }
        return "=";
    }
}
