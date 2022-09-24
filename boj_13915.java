import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String str;
        while ((str = br.readLine()) != null) {
            int iN = Integer.parseInt(str);
            int iCount = 0;
            HashSet<Integer> set = new HashSet<>();
            while (iN-- > 0) {
                String FlightList = br.readLine();
                int iTemp = 0;
                int iSize = FlightList.length();
                for (int i = 0; i < iSize; ++i) {
                    iTemp = iTemp | (1 << (FlightList.charAt(i) - '0'));
                }
                if (!set.contains(iTemp)) {
                    set.add(iTemp);
                    ++iCount;
                }
            }
            sb.append(iCount + "\n");
        }
        System.out.println(sb);
    }
}
