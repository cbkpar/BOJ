import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int iN = Integer.parseInt(st.nextToken());
        int iM = Integer.parseInt(st.nextToken());
        int[] arrNumber = new int[iN];
        for (int i = 0; i < iN; ++i) {
            arrNumber[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(arrNumber);
        HashMap<Integer, Integer> mapNumber = new HashMap<>();
        int iIndex = 0;
        for (int iNumber : arrNumber) {
            if (!mapNumber.containsKey(iNumber)) {
                mapNumber.put(iNumber, iIndex);
            }
            ++iIndex;
        }
        while (iM-- > 0) {
            int iNumber = Integer.parseInt(br.readLine());
            if (mapNumber.containsKey(iNumber)) {
                sb.append(mapNumber.get(iNumber) + "\n");
            } else {
                sb.append("-1\n");
            }
        }
        System.out.println(sb);
    }
}
