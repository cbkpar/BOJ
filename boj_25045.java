import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String args[]) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int iN = Integer.parseInt(st.nextToken());
        int iM = Integer.parseInt(st.nextToken());
        long[] lProduct = InputData(iN);
        long[] lCustomer = InputData(iM);
        System.out.println(Solve(lProduct, lCustomer));
    }

    private static long[] InputData(int _iCount) throws IOException {
        long[] lArr = new long[_iCount];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < _iCount; ++i) {
            lArr[i] = Long.parseLong(st.nextToken());
        }
        return lArr;
    }

    private static long Solve(long[] _lProduct, long[] _lCustomer) {
        int iProductSize = _lProduct.length;
        int iCustomerSize = _lCustomer.length;
        long lSumSatisfication = 0;
        Arrays.sort(_lProduct);
        Arrays.sort(_lCustomer);
        for (int i = 0; i < iCustomerSize; ++i) {
            if (iProductSize - i - 1 < 0) break;
            if (_lProduct[iProductSize - i - 1] - _lCustomer[i] < 0) break;
            lSumSatisfication += _lProduct[iProductSize - i - 1] - _lCustomer[i];
        }
        return lSumSatisfication;
    }
}
