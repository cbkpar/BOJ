import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());
        long[] presum = new long[n + 1];
        long[] prepowsum = new long[n + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            long t = Long.parseLong(st.nextToken());
            presum[i] = presum[i - 1] + t;
            prepowsum[i] = prepowsum[i - 1] + t * t;
        }
        while (q-- > 0) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken()) - 1;
            int e = Integer.parseInt(st.nextToken());
            long k = ((presum[e] - presum[s]) * (presum[e] - presum[s]) - (prepowsum[e] - prepowsum[s])) / 2;
            sb.append(k + "\n");
        }
        System.out.println(sb);
    }
}
