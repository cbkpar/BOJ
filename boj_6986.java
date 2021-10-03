import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, k, i;
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        double[] arr = new double[n];
        for (i = 0; i < n; i++) arr[i] = Double.parseDouble(br.readLine());
        Arrays.sort(arr);
        double s = 0;
        for (i = k; i < n - k; i++) s += arr[i];
        System.out.printf("%.2f\n%.2f", (s / (n - 2 * k)), ((s + (arr[k] + arr[n - k - 1]) * k)) / n);
    }
}
