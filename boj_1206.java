import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), ".");
            st.nextToken();
            arr[i] = Integer.parseInt(st.nextToken());
        }
        for (int i = 1; ; i++) {
            HashSet<Integer> set = new HashSet<>();
            for (int j = 0; j < i; j++) {
                set.add(((1000 * j) / i) % 1000);
            }
            boolean chk = true;
            for (int j = 0; j < n; j++) {
                if (!set.contains(arr[j])) {
                    chk = false;
                    break;
                }
            }
            if (chk) {
                System.out.println(i);
                return;
            }
        }
    }
}
