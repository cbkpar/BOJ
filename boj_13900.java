import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long sum = 0;
        long presum = 0;
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        while (n-- > 0) {
            long t = Long.parseLong(st.nextToken());
            sum += presum * t;
            presum += t;
        }
        System.out.println(sum);
    }
}
