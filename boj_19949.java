import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int[] ans = new int[10];
    static int[] arr = new int[10];
    static int cases = 0;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 10; i++) ans[i] = Integer.parseInt(st.nextToken());
        dfs(0, 0);
        System.out.println(cases);
    }

    private static void dfs(int n, int score) {
        if (n == 10) {
            if (score >= 5) cases++;
            return;
        }
        for (int i = 1; i <= 5; i++) {
            if (n >= 2) {
                if (arr[n - 1] == arr[n - 2] && arr[n - 1] == i) continue;
            }
            arr[n] = i;
            dfs(n + 1, score + (ans[n] == i ? 1 : 0));
        }
    }
}
