import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        while (true) {
            double dR = Double.parseDouble(br.readLine());
            if (dR == 0) {
                break;
            }
            if (dR == 1) {
                sb.append("5.00\n");
            } else {
                double dAns = (dR * dR * dR * dR * dR - 1) / (dR - 1);
                sb.append(String.format("%.02f\n", dAns));
            }
        }
        System.out.println(sb);
    }
}
