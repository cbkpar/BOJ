import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int iN = Integer.parseInt(br.readLine());
        String str = br.readLine();
        int iChicken = 0;
        for (int i = 0; i < iN; ++i) {
            if ('C' == str.charAt(i)) {
                ++iChicken;
            }
        }
        if (0 == iChicken % (iN - iChicken + 1)) {
            System.out.println(iChicken / (iN - iChicken + 1));
        } else {
            System.out.println((iChicken / (iN - iChicken + 1) + 1));
        }
    }
}
