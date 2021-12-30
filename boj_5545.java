import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int cost_total = Integer.parseInt(st.nextToken());
        int cost_topping = Integer.parseInt(st.nextToken());
        int[] arr = new int[n];
        int cal = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(br.readLine());
        Arrays.sort(arr);
        for (int i = n - 1; i >= 0; i--) {
            if (cal * (cost_total + cost_topping) < (cal + arr[i]) * cost_total) {
                cal += arr[i];
                cost_total += cost_topping;
            }
        }
        System.out.println(cal / cost_total);
    }
}
