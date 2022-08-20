import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int iN = Integer.parseInt(br.readLine());
        int[] arrNumber = new int[50001];
        StringTokenizer st = new StringTokenizer(br.readLine());
        while (iN-- > 0) {
            ++arrNumber[Integer.parseInt(st.nextToken())];
        }
        int iMax = 0;
        for (int i = 1; i <= 50000; ++i) {
            iMax = Math.max(iMax, arrNumber[i]);
        }
        System.out.println(iMax);
    }
}
