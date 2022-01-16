import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] arr = new int[100];
        int t = 0;
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int len = Integer.parseInt(st.nextToken());
            int speed = Integer.parseInt(st.nextToken());
            while (len-- > 0) arr[t++] = speed;
        }
        int mx = 0;
        t = 0;
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int len = Integer.parseInt(st.nextToken());
            int speed = Integer.parseInt(st.nextToken());
            while (len-- > 0) {
                mx = Math.max(mx, speed - arr[t++]);
            }
        }
        System.out.println(mx);
    }
}
