import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int ans = 0;
        int[] arr = new int[12];
        for (int i = 1; i <= 11; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            arr[i] = Integer.parseInt(st.nextToken());
            ans += Integer.parseInt(st.nextToken()) * 20;
        }
        Arrays.sort(arr);
        for (int i = 1; i <= 11; i++) {
            arr[i] += arr[i - 1];
            ans += arr[i];
        }
        System.out.println(ans);
    }
}
