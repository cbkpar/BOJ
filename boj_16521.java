import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), ".");
        int R = Integer.parseInt(st.nextToken()) * 100;
        R += Integer.parseInt(st.nextToken());
        for (int i = 1; i <= 36000; i++) {
            if ((R * i) % 36000 == 0) {
                System.out.println(i);
                return;
            }
        }
    }
}
