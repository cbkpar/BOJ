import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String A = br.readLine();
        String B = br.readLine();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (A.charAt(i) != B.charAt(i)) {
                cnt++;
                i++;
                while (i < n && A.charAt(i) != B.charAt(i)) i++;
            }
        }
        System.out.println(cnt);
    }
}
