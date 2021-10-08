import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int[] arr = new int[2000001];
        int n = Integer.parseInt(br.readLine());
        while (n-- > 0) arr[Integer.parseInt(br.readLine()) + 1000000]++;
        for (int i = 0; i <= 2000000; i++) {
            while (arr[i]-- > 0) {
                sb.append((i - 1000000) + "\n");
            }
        }
        System.out.println(sb);
    }
}
