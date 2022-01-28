import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        long[][] road = new long[n][3];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) road[i][0] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i < n; i++) road[i][1] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n - 1; i++) road[i][2] = Integer.parseInt(st.nextToken());

        for (int i = 2; i < n; i++) road[i][1] += road[i - 1][1];
        for (int i = n - 2; i >= 0; i--) road[i][2] += road[i + 1][2];

        long ans = Long.MAX_VALUE;
        long num = 0;

        for (int i = 0; i < n; i++) {
            long tmp = road[i][0] + road[i][1] + road[i][2];
            if (tmp < ans) {
                ans = tmp;
                num = i;
            }
        }
        System.out.println((num + 1) + " " + ans);
    }
}
