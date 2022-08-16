import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int iA = Integer.parseInt(st.nextToken());
        int iK = Integer.parseInt(st.nextToken());
        int[] arrdp = new int[iK + 1];
        Arrays.fill(arrdp, 1000000000);
        arrdp[iA] = 0;
        for (int i = iA + 1; i <= iK; ++i) {
            arrdp[i] = arrdp[i - 1] + 1;
            if (i % 2 == 0) {
                arrdp[i] = Math.min(arrdp[i], arrdp[i / 2] + 1);
            }
        }
        System.out.println(arrdp[iK]);
    }
}
