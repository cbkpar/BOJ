import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, t;
        n = Integer.parseInt(br.readLine());
        if (n % 3 == 0) {
            t = (n / 3) * 2;
        } else if (n % 3 == 1) {
            t = ((n - 4) / 3) * 2 + 2;
        } else {
            t = ((n - 2) / 3) * 2 + 1;
        }
        System.out.println((n + 1) / 2 + " " + t);
    }
}
