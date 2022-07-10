import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int iN = Integer.parseInt(br.readLine());
        int iAns = 2;
        for (int i = 0; i < iN; ++i) {
            iAns *= 3;
        }
        iAns /= 9;
        System.out.println(iAns);
    }
}
