import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String str = br.readLine();
        int sz = str.length();
        int sq = (int) Math.sqrt(sz);
        for (int i = sq; i >= 1; i--) {
            if (sz % i == 0) {
                for (int j = 0; j < i; j++) {
                    for (int k = 0; k < sz / i; k++) {
                        sb.append(str.charAt(j + k * i));
                    }
                }
                System.out.println(sb);
                return;
            }
        }
    }
}
