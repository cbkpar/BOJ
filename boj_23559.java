import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        int ans = 0;
        ArrayList<Integer> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            ans += b;
            arr.add(a - b);
        }
        Collections.sort(arr, Collections.reverseOrder());
        x -= 1000 * n;
        for (int i = 0; i < n; i++) {
            if (x < 4000) break;
            if (arr.get(i) <= 0) break;
            ans += arr.get(i);
            x -= 4000;
        }
        System.out.println(ans);
    }
}
