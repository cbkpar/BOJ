import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] arr = new int[33];
        for (int i = 0; i < n; i++) {
            int num = Integer.parseInt(st.nextToken());
            int cnt = 0;
            while (num > 1) {
                num /= 2;
                cnt++;
            }
            arr[cnt]++;
        }
        int sum = 0;
        int amount = 0;
        for (int i = 0; i <= 32; i++) {
            if (amount + arr[i] > (n + 1) / 2) {
                sum += i * ((n + 1) / 2 - amount);
                break;
            } else {
                sum += i * arr[i];
                amount += arr[i];
            }
        }
        System.out.println(sum + 1);
    }
}
