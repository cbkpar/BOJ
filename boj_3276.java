import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int sq = (int) Math.sqrt(n - 1) + 1;
        if (n <= sq * (sq - 1)) {
            System.out.println(sq + " " + (sq - 1));
        } else {
            System.out.println(sq + " " + sq);
        }
    }
}
