import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int iN = Integer.parseInt(br.readLine());

        int[] arrMass = new int[iN + 1];
        for (int i = iN; i > 0; ) {
            int iTemp = i;
            int iNext = getNextMass(i);
            for (int j = iNext - i; j <= iTemp; ++j) {
                arrMass[i--] = j;
            }
        }
        for (int i = 1; i <= iN; ++i) {
            sb.append(arrMass[i] + "\n");
        }
        System.out.println(sb);
    }

    private static int getNextMass(int _iN) {
        _iN |= _iN >> 1;
        _iN |= _iN >> 2;
        _iN |= _iN >> 4;
        _iN |= _iN >> 8;
        _iN |= _iN >> 16;
        return ++_iN;
    }
}
