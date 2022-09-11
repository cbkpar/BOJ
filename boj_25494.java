import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int iT = Integer.parseInt(br.readLine());
        while (iT-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int iA = Integer.parseInt(st.nextToken());
            int iB = Integer.parseInt(st.nextToken());
            int iC = Integer.parseInt(st.nextToken());
            int iAns = 0;
            for (int i = 1; i <= iA; ++i) {
                for (int j = 1; j <= iB; ++j) {
                    for (int k = 1; k <= iC; ++k) {
                        if (i % j == j % k && j % i == k % j) {
                            ++iAns;
                        }
                    }
                }
            }
            sb.append(iAns + "\n");
        }
        System.out.println(sb);
    }
}
