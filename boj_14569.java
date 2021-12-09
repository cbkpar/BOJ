import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        long[] subject = new long[n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int k = Integer.parseInt(st.nextToken());
            long tmp = 0;
            for (int j = 0; j < k; j++) {
                tmp += 1L << Integer.parseInt(st.nextToken());
            }
            subject[i] = tmp;
        }
        int m = Integer.parseInt(br.readLine());
        while (m-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int p = Integer.parseInt(st.nextToken());
            long tmp = 0;
            for (int i = 0; i < p; i++) tmp += 1L << Integer.parseInt(st.nextToken());
            int cnt = 0;
            for (int i = 0; i < n; i++) if ((subject[i] & tmp) == subject[i]) cnt++;
            sb.append(cnt + "\n");
        }
        System.out.println(sb);
    }
}
