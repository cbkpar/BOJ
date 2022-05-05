import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int[] iCount = new int[1000001];
        for (int i = 2; i <= 1000000; ++i) {
            int t = 0;
            for (int j = i; j <= 1000000; j += i + t) {
                ++iCount[j];
                ++t;
            }
        }
        while (true) {
            int n = Integer.parseInt(br.readLine());
            if (0 == n) break;
            sb.append(iCount[n] + "\n");
        }
        System.out.println(sb);
    }
}
