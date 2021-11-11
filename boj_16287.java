import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int w = Integer.parseInt(st.nextToken());
        boolean[] chk = new boolean[w + 1];
        int n = Integer.parseInt(st.nextToken());
        int[] arr = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] + arr[j] > w) continue;
                if (chk[w - (arr[i] + arr[j])]) {
                    System.out.println("YES");
                    return;
                }
            }
            for (int j = 0; j < i; j++) if (arr[i] + arr[j] < w) chk[arr[i] + arr[j]] = true;
        }
        System.out.println("NO");
    }
}
