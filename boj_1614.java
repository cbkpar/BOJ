import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int finger = Integer.parseInt(br.readLine());
        long num = Integer.parseInt(br.readLine());
        if (finger == 1) {
            System.out.println(num * 8);
        } else if (finger == 2) {
            System.out.println((num / 2) * 8 + (num % 2 == 1 ? 7 : 1));
        } else if (finger == 3) {
            System.out.println((num / 2) * 8 + (num % 2 == 1 ? 6 : 2));
        } else if (finger == 4) {
            System.out.println((num / 2) * 8 + (num % 2 == 1 ? 5 : 3));
        } else {
            System.out.println(num * 8 + 4);
        }
    }
}
