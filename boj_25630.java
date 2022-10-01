import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int iN = Integer.parseInt(br.readLine());
        String str = br.readLine();
        int iCount = 0;
        for (int i = 0; i < iN; ++i) {
            if (str.charAt(i) != str.charAt(iN - 1 - i)) {
                ++iCount;
            }
        }
        System.out.println(iCount / 2);
    }
}
