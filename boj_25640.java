import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int iCount = 0;
        int iN = Integer.parseInt(br.readLine());
        while (iN-- > 0) {
            if (br.readLine().equals(str)) {
                ++iCount;
            }
        }
        System.out.println(iCount);
    }
}
