import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int iN = Integer.parseInt(br.readLine());
        int[] arrNumber = new int[iN];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < iN; ++i) {
            arrNumber[i] = Integer.parseInt(st.nextToken());
        }
        int iK = Integer.parseInt(br.readLine());
        int iDiff = iN / iK;
        for (int i = 0; i < iK; ++i) {
            ArrayList<Integer> arrList = new ArrayList<>();
            for (int j = 0; j < iDiff; ++j) {
                arrList.add(arrNumber[i * iDiff + j]);
            }
            Collections.sort(arrList);
            for (int j = 0; j < iDiff; ++j) {
                arrNumber[i * iDiff + j] = arrList.get(j);
            }
        }
        for (int i = 0; i < iN; ++i) {
            if (i == iN - 1) {
                sb.append(arrNumber[i] + "\n");
            } else {
                sb.append(arrNumber[i] + " ");
            }
        }
        System.out.println(sb);
    }
}
