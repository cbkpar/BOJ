import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n, d, ans;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());
        for (int i = 1; i < 10; i++) {
            dfs(i, (i == d ? 1 : 0));
        }
        System.out.println(ans);
    }

    public static void dfs(int num, int s) {
        if (num > n) return;
        ans += s;
        for (int i = 0; i < 10; i++) {
            dfs(num * 10 + i, s + (i == d ? 1 : 0));
        }
    }
}
