import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int iSize = str.length();
        int iNumber = 0;
        for (int i = 4; i < iSize; ++i) {
            if (str.charAt(i) >= 'A' && str.charAt(i) <= 'Z') {
                iNumber *= 100;
                iNumber += str.charAt(i) - 'A' + 10;
            } else {
                iNumber *= 10;
                iNumber += str.charAt(i) - '0';
            }
            iNumber %= 97;
        }
        for (int i = 0; i < 4; ++i) {
            if (str.charAt(i) >= 'A' && str.charAt(i) <= 'Z') {
                iNumber *= 100;
                iNumber += str.charAt(i) - 'A' + 10;
            } else {
                iNumber *= 10;
                iNumber += str.charAt(i) - '0';
            }
            iNumber %= 97;
        }
        if (1 == iNumber) {
            System.out.println("correct");
        } else {
            System.out.println("incorrect");
        }
    }
}
