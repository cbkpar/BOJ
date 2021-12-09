import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        while (n-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String s = st.nextToken();
            long N = Integer.parseInt(st.nextToken());
            long T = Integer.parseInt(st.nextToken());
            long L = Integer.parseInt(st.nextToken());
            boolean chk = true;
            if (s.equals("O(N)")) {
                if (N > L * 100000000 / T) chk = false;
            } else if (s.equals("O(N^2)")) {
                if (N * N > L * 100000000 / T) chk = false;
            } else if (s.equals("O(N^3)")) {
                if (N * N * N > L * 100000000 / T) chk = false;
            } else if (s.equals("O(2^N)")) {
                long tmp = 1;
                for (long i = 0; i < N; i++) {
                    tmp *= 2;
                    if (tmp > L * 100000000 / T) {
                        chk = false;
                        break;
                    }
                }
            } else {
                long tmp = 1;
                for (long i = 1; i <= N; i++) {
                    tmp *= i;
                    if (tmp > L * 100000000 / T) {
                        chk = false;
                        break;
                    }
                }
            }
            sb.append(chk ? "May Pass.\n" : "TLE!\n");
        }
        System.out.println(sb);
    }
}
