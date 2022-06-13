import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int iN = Integer.parseInt(br.readLine());
        for (int i = 0; i < iN * 4; ++i) {
            for (int j = 0; j < iN; ++j) {
                sb.append("@");
            }
            sb.append("\n");
        }
        for (int i = 0; i < iN; ++i) {
            for (int j = 0; j < iN * 5; ++j) {
                sb.append("@");
            }
            sb.append("\n");
        }
        System.out.println(sb);
    }
}
