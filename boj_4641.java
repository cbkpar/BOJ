import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            HashSet<Integer> set = new HashSet<>();
            int iN = Integer.parseInt(st.nextToken());
            if (-1 == iN) break;
            int iCount = 0;
            set.add(iN);
            while (true) {
                iN = Integer.parseInt(st.nextToken());
                if (0 == iN) {
                    sb.append(iCount + "\n");
                    break;
                }
                if (0 == iN % 2) {
                    if (set.contains(iN / 2)) ++iCount;
                }
                if (set.contains(iN * 2)) ++iCount;
                set.add(iN);
            }
        }
        System.out.println(sb);
    }
}
