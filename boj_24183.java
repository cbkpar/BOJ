import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        double C4 = Double.parseDouble(st.nextToken());
        double A3 = Double.parseDouble(st.nextToken());
        double A4 = Double.parseDouble(st.nextToken());
        C4 *= 0.229 * 0.324 * 2;
        A3 *= 0.297 * 0.420 * 2;
        A4 *= 0.21 * 0.297;
        System.out.println(C4 + A3 + A4);
    }
}
