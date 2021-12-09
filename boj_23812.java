import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        char[] a = new char[5 * n];
        char[] b = new char[5 * n];
        for (int i = 0; i < n; i++) a[i] = '@';
        for (int i = n; i < 4 * n; i++) a[i] = ' ';
        for (int i = 4 * n; i < 5 * n; i++) a[i] = '@';
        for (int i = 0; i < 5 * n; i++) b[i] = '@';
        for (int t = 0; t < 5; t++) {
            if (t % 2 == 0) {
                for (int i = 0; i < n; i++) {
                    sb.append(a);
                    sb.append("\n");
                }
            } else {
                for (int i = 0; i < n; i++) {
                    sb.append(b);
                    sb.append("\n");
                }
            }
        }
        System.out.println(sb);
    }
}
