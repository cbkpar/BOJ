import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        int maxX = n;
        int maxY = n;
        while (c-- > 0) {
            st = new StringTokenizer(br.readLine());
            int y = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());
            if (x >= maxX || y >= maxY) continue;
            if (y * maxX >= x * maxY) {
                maxY = y;
            } else {
                maxX = x;
            }
        }
        System.out.println(maxX * maxY);
    }
}
