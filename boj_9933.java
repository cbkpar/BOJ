import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int iN = Integer.parseInt(br.readLine());
        String[] arr = new String[iN];
        for (int i = 0; i < iN; ++i) {
            arr[i] = br.readLine();
        }
        for (int i = 0; i < iN; ++i) {
            if (1 == arr[i].length() % 2) {
                for (int j = 0; j < iN; ++j) {
                    if (arr[i].length() != arr[j].length()) break;
                    int iLength = arr[i].length();
                    for (int k = 0; k < iLength; ++k) {
                        if (arr[i].charAt(k) != arr[j].charAt(iLength - k - 1)) break;
                        if (k + 1 == iLength) {
                            System.out.println(iLength + " " + arr[i].charAt(iLength / 2));
                            return;
                        }
                    }

                }
            }
        }
    }
}
