import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] arr = new int[n][2];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken());
        }
        long ans = 0;
        int xmin = arr[0][0];
        int xmax = arr[0][0];
        int ymin = arr[0][1];
        int ymax = arr[0][1];
        for (int i = 1; i < n; i++) {
            xmin = Math.min(xmin, arr[i][0]);
            xmax = Math.max(xmax, arr[i][0]);
            ymin = Math.min(ymin, arr[i][1]);
            ymax = Math.max(ymax, arr[i][1]);
            ans += Math.abs(arr[i][0] - arr[i - 1][0]) + Math.abs(arr[i][1] - arr[i - 1][1]);
        }
        ans += Math.abs(arr[n - 1][0] - arr[0][0]) + Math.abs(arr[n - 1][1] - arr[0][1]);
        System.out.println((ans - (xmax - xmin + ymax - ymin) * 2));
    }
}
