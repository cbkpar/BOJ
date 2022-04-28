import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int iN = Integer.parseInt(st.nextToken());
        int iK = Integer.parseInt(st.nextToken());
        int[] arr = new int[iN];
        for (int i = 0; i < iN; ++i) {
            if (iK >= iN - i - 1) {
                arr[i] = iN - i;
                iK -= iN - i - 1;
            } else {
                for (int j = i; j < iN; ++j) {
                    arr[j] = j - i + 1;
                }
                break;
            }
        }
        for (int i = 1; i <= iK; ++i) {
            int iTemp = arr[iN - i];
            arr[iN - i] = arr[iN - i - 1];
            arr[iN - i - 1] = iTemp;
        }
        for (int i = 0; i < iN; ++i) {
            sb.append(arr[i] + " ");
        }
        System.out.println(sb.toString().trim());
    }
}
