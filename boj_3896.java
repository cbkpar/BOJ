import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        boolean[] isprime = new boolean[12999710];
        for (int i = 2; i * i <= 1299709; i++) {
            for (int j = i * i; j <= 1299709; j += i) {
                isprime[j] = true;
            }
        }
        int iT = Integer.parseInt(br.readLine());
        while (iT-- > 0) {
            int iK = Integer.parseInt(br.readLine());
            int iLeft = iK;
            while (isprime[iLeft]) iLeft--;
            int iRight = iK;
            while (isprime[iRight]) iRight++;
            sb.append((iRight - iLeft) + "\n");
        }
        System.out.println(sb);
    }
}
