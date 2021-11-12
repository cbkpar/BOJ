import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int sum = 0;
        while (n-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int c = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            sum += c * k;
        }
        System.out.println(sum);
    }
}
