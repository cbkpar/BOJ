import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        long t = Integer.parseInt(st.nextToken());
        long sum = 0;
        st = new StringTokenizer(br.readLine());
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            sum += arr[i];
        }
        if (sum % k != 0) {
            System.out.println("NO");
            return;
        }
        Arrays.sort(arr);
        long need = 0;
        int p = 0;
        int q = n - 1;
        while (p < q) {
            if (arr[p] + arr[q] >= k) {
                int tmp = k - arr[q];
                arr[p] -= tmp;
                need += tmp;
                q--;
            } else {
                arr[q] += arr[p];
                need += arr[p];
                p++;
            }
        }
        System.out.println(t >= need ? "YES" : "NO");
    }
}
