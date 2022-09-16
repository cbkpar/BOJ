import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int iN = Integer.parseInt(br.readLine());
        int[] arr = new int[6];
        int[] arrIndex = new int[6];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= iN; ++i) {
            int iNumber = Integer.parseInt(st.nextToken()) - 1;
            if (arr[iNumber] == 0) {
                arrIndex[iNumber] = i;
            }
            ++arr[iNumber];
        }
        for (int i = 5; i >= 0; --i) {
            if (arr[i] == 1) {
                System.out.println(arrIndex[i]);
                return;
            }
        }
        System.out.println("none");
        return;
    }
}
