import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        int[] arrNumber = InputData();
        int iAnswer = Solve(arrNumber);
        System.out.println(iAnswer);
    }

    private static int[] InputData() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int iN = Integer.parseInt(br.readLine());
        int[] arrNumber = new int[iN];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < iN; ++i) {
            arrNumber[i] = Integer.parseInt(st.nextToken());
        }
        return arrNumber;
    }

    private static int Solve(int[] _arrNumber) {
        ArrayList<Integer> arrTemp = new ArrayList<>();
        arrTemp.add(Integer.MIN_VALUE);
        int iSize = _arrNumber.length;
        for (int i = 0; i < iSize; ++i) {
            if (_arrNumber[i] > arrTemp.get(arrTemp.size() - 1)) {
                arrTemp.add(_arrNumber[i]);
            } else {
                int iLeft = 0;
                int iRight = arrTemp.size() - 1;
                while (iLeft < iRight) {
                    int iMid = (iLeft + iRight) / 2;
                    if (_arrNumber[i] > arrTemp.get(iMid)) {
                        iLeft = iMid + 1;
                    } else {
                        iRight = iMid;
                    }
                }
                arrTemp.set(iLeft, _arrNumber[i]);
            }
        }
        return arrTemp.size() - 1;
    }
}
