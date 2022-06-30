import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int iH = Integer.parseInt(st.nextToken());
        int iX = Integer.parseInt(st.nextToken());
        long lX = iX;
        long lSize = 0;
        for (int i = 0; i < iH; ++i) {
            lSize += Integer.parseInt(br.readLine()) * lX;
            lSize %= 1000000007;
            lX = (lX * iX) % 1000000007;
        }
        System.out.println(lSize);
    }
}
