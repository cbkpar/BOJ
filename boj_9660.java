import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long lN = Long.parseLong(br.readLine());
        if (lN % 7 == 0 || lN % 7 == 2) {
            System.out.println("CY");
        } else {
            System.out.println("SK");
        }
    }
}
