import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int prev = Integer.parseInt(br.readLine());
        int sum = 0;
        while (n-- > 0) {
            int next = Integer.parseInt(br.readLine());
            int tmp = Math.abs(next - prev);
            if (tmp > 180) tmp = 360 - tmp;
            sum += tmp;
            prev = next;
        }
        System.out.println(sum);
    }
}
