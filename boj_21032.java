import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int even = 0;
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            int t = Integer.parseInt(st.nextToken());
            if (t % 2 == 0) even++;
        }
        int odd = n - even;
        int ans = Math.min(even, odd) + (odd - Math.min(even, odd)) / 2;
        System.out.println(ans);
    }
}
