import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int iN = Integer.parseInt(br.readLine());
        if (iN < 100) {
            System.out.println("99");
        } else {
            if (iN % 100 >= 49) {
                System.out.println((iN / 100) * 100 + 99);
            } else {
                System.out.println((iN / 100) * 100 - 1);
            }
        }
    }
}
