import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int i, j;
        int k = Integer.parseInt(br.readLine());
        boolean[] p = new boolean[8000001];
        p[0] = p[1] = true;
        for (i = 2; i * i <= 8000000; i++) if (!p[i]) for (j = i * i; j <= 8000000; j += i) p[j] = true;
        for (i = 2; i <= 8000000; i++) {
            if (!p[i]) {
                if (--k == 0) {
                    System.out.println(i);
                    return;
                }
            }
        }
    }
}
