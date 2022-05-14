import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int iN = Integer.parseInt(br.readLine());
        int iCount = 0;
        HashSet<String> set = new HashSet<>();
        while (iN-- > 0) {
            String str = br.readLine();
            if (str.equals("ENTER")) {
                set.clear();
                continue;
            }
            if (set.contains(str)) continue;
            set.add(str);
            ++iCount;
        }
        System.out.println(iCount);
    }
}
