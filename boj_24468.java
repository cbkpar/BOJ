import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {


    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int l = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        int t = Integer.parseInt(st.nextToken());
        int[] dist = new int[n];
        boolean[] isleft = new boolean[n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            dist[i] = Integer.parseInt(st.nextToken());
            isleft[i] = st.nextToken().charAt(0) == 'L' ? true : false;
        }
        int cnt = 0;
        if (t >= l) {
            int tmp = t / l;
            cnt += tmp * (n) * (n - 1) / 2;
            t = t % l;
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (dist[i] < dist[j]) {
                    int left = dist[i] + (isleft[i] ? -t : t);
                    if (left < 0) left = Math.abs(left);
                    if (left > l) left = 2 * l - left;
                    int right = dist[j] + (isleft[j] ? -t : t);
                    if (right < 0) right = Math.abs(right);
                    if (right > l) right = 2 * l - right;
                    if (left >= right) cnt++;
                } else {
                    int left = dist[j] + (isleft[j] ? -t : t);
                    if (left < 0) left = Math.abs(left);
                    if (left > l) left = 2 * l - left;
                    int right = dist[i] + (isleft[i] ? -t : t);
                    if (right < 0) right = Math.abs(right);
                    if (right > l) right = 2 * l - right;
                    if (left >= right) cnt++;
                }
            }
        }
        System.out.println(cnt);
    }
}
