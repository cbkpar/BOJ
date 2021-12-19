import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int x = 0;
        int y = 0;
        StringTokenizer st = new StringTokenizer(br.readLine());
        try {
            x = Integer.parseInt(st.nextToken());
        } catch (NumberFormatException e) {
            System.out.println("NaN");
            return;
        }
        try {
            y = Integer.parseInt(st.nextToken());
        } catch (NumberFormatException e) {
            System.out.println("NaN");
            return;
        }
        System.out.println(x - y);
    }
}
