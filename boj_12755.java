import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n, t, k;
        n = Integer.parseInt(br.readLine());
        t = 1;
        k = 1;
        while (true) {
            if (n > t * k * 9) {
                n -= t * k * 9;
                t++;
                k *= 10;
            } else {
                System.out.println(Integer.toString(k + (n - 1) / t).charAt((n - 1) % t));
                return;
            }
        }
    }
}
