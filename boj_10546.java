import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine()) * 2 - 1;
        HashSet<String> set = new HashSet<>();
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            if (set.contains(str)) {
                set.remove(str);
            } else {
                set.add(str);
            }
        }
        for (String str : set) {
            System.out.println(str);
        }
    }
}
