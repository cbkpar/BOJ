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
        int m = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                int intensity = Integer.parseInt(st.nextToken()) * 2126;
                intensity += Integer.parseInt(st.nextToken()) * 7152;
                intensity += Integer.parseInt(st.nextToken()) * 722;
                if (intensity < 510000) {
                    sb.append('#');
                } else if (intensity < 1020000) {
                    sb.append('o');
                } else if (intensity < 1530000) {
                    sb.append('+');
                } else if (intensity < 2040000) {
                    sb.append('-');
                } else {
                    sb.append('.');
                }
            }
            sb.append("\n");
        }
        System.out.println(sb);
    }
}
