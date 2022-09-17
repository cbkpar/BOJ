import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int iCount = 0;
        int iLen = str.length();
        for (int i = 0; i < iLen; ++i) {
            int iNumber = str.charAt(i) - '0';
            if (i % 2 == 0) {
                iNumber *= 2;
            }
            if (iNumber >= 10) {
                iCount += iNumber - 9;
            } else {
                iCount += iNumber;
            }
        }
        if (iCount % 10 == 0) {
            System.out.println("DA");
        } else {
            System.out.println("NE");
        }
    }
}
