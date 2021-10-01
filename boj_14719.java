import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int h, w, i, t, ans;
        StringTokenizer st = new StringTokenizer(br.readLine());
        h = Integer.parseInt(st.nextToken());
        w = Integer.parseInt(st.nextToken());
        int[] arr = new int[w];
        int[] lmax = new int[w];
        int[] rmax = new int[w];
        st = new StringTokenizer(br.readLine());
        for (i = 0; i < w; i++) arr[i] = Integer.parseInt(st.nextToken());
        lmax[0] = arr[0];
        for (i = 1; i < w; i++) lmax[i] = Math.max(lmax[i - 1], arr[i]);
        rmax[w - 1] = arr[w - 1];
        for (i = w - 2; i >= 0; i--) rmax[i] = Math.max(rmax[i + 1], arr[i]);
        ans = 0;
        for (i = 1; i < w - 1; i++) {
            t = Math.min(lmax[i - 1], rmax[i + 1]);
            if (t > arr[i]) ans += t - arr[i];
        }
        System.out.println(ans);
    }
}
