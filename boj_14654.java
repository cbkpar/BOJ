import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, i, c, ans, mx;
        boolean ace = false;
        n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());
        ans = mx = 1;
        st = new StringTokenizer(br.readLine());
        c = competiton(arr[0], Integer.parseInt(st.nextToken()));
        if (c == 1) ace = true;
        for (i = 1; i < n; i++) {
            c = competiton(arr[i], Integer.parseInt(st.nextToken()));
            if (c == 0) {
                ace = !ace;
                ans = 1;
            } else if (c == 1) {
                if (ace) {
                    mx = Math.max(mx, ++ans);
                } else {
                    ace = true;
                    ans = 1;
                }
            } else {
                if (!ace) {
                    mx = Math.max(mx, ++ans);
                } else {
                    ace = false;
                    ans = 1;
                }
            }
        }
        System.out.println(mx);
    }

    public static int competiton(int a, int b) {
        if (a == b) return 0;
        if (a == 1 && b == 3) return 1;
        if (a == 2 && b == 1) return 1;
        if (a == 3 && b == 2) return 1;
        return 2;
    }
}
