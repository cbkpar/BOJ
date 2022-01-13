import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        if (n == 1) {
            System.out.println("권병장님, 중대장님이 찾으십니다");
            return;
        }
        int[] pos = new int[n];
        int[] power = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) pos[i] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n - 1; i++) power[i] = Integer.parseInt(st.nextToken());
        int mx = 0;
        for (int i = 0; i < n; i++) {
            if (mx < pos[i]) break;
            mx = Math.max(mx, pos[i] + power[i]);
        }
        if (mx >= pos[n - 1]) {
            System.out.println("권병장님, 중대장님이 찾으십니다");
        } else {
            System.out.println("엄마 나 전역 늦어질 것 같아");
        }
    }
}
