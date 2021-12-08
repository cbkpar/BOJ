import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        while (true) {
            int n = Integer.parseInt(br.readLine());
            if (n == 0) break;
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(br.readLine());
            Arrays.sort(arr);
            int mx = 0;
            for (int i = 0; i < n; i++) {
                if (mx + 200 < arr[i]) break;
                mx = arr[i];
            }
            sb.append(mx >= 1322 ? "POSSIBLE\n" : "IMPOSSIBLE\n");
        }
        System.out.println(sb);
    }
}
