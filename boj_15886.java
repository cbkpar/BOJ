import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String str = br.readLine();
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            if (str.charAt(i) != str.charAt(i - 1)) cnt++;
        }
        System.out.println((cnt + 1) / 2);
    }
}
