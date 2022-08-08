import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long lK = Long.parseLong(st.nextToken());
        long lA = Long.parseLong(st.nextToken());
        long lB = Long.parseLong(st.nextToken());
        if (lA < 0) {
            lA /= lK;
        } else {
            if (0 == lA % lK) {
                lA /= lK;
            } else {
                lA = lA / lK + 1;
            }
        }
        if (lB < 0) {
            if (0 == lB % lK) {
                lB /= lK;
            } else {
                lB = lB / lK - 1;
            }
        } else {
            lB /= lK;
        }
        if (lB - lA + 1 > 0) {
            System.out.println(lB - lA + 1);
        } else {
            System.out.println("0");
        }
    }
}
