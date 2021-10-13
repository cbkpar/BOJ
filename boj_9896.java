import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        String str = br.readLine();
        sb.append(str.charAt(0));
        for (int i = 1; i < n; i++) sb.append((str.charAt(i) - '0' + str.charAt(i - 1) - '0') % 2 == 0 ? "0" : "1");
        System.out.println(sb);
    }
}
