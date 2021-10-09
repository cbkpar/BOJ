import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int[] arr = new int[20];
            int cnt = 0;
            for (int i = 0; i < 20; i++) arr[i] = Integer.parseInt(st.nextToken());
            for (int i = 1; i < 20; i++) {
                for (int j = 0; j < i; j++) {
                    if (arr[i] < arr[j]) cnt++;
                }
            }
            sb.append(n + " " + cnt + "\n");
        }
        System.out.println(sb);
    }
}
