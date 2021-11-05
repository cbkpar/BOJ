import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] cow = new int[n];
        int[] stall = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) cow[i] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) stall[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(cow);
        Arrays.sort(stall);
        long ans = 1;
        for (int i = 0; i < n; i++) {
            long cnt = -i;
            for (int j = 0; j < n; j++) {
                if (cow[j] > stall[i]) break;
                cnt++;
            }
            ans *= cnt;
        }
        System.out.println(ans);
    }
}
