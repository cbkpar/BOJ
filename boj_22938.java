import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long lX1 = Long.parseLong(st.nextToken());
        long lY1 = Long.parseLong(st.nextToken());
        long lR1 = Long.parseLong(st.nextToken());
        st = new StringTokenizer(br.readLine());
        long lX2 = Long.parseLong(st.nextToken());
        long lY2 = Long.parseLong(st.nextToken());
        long lR2 = Long.parseLong(st.nextToken());

        long dX = lX1 - lX2;
        long dY = lY1 - lY2;

        if (dX * dX + dY * dY < (lR1 + lR2) * (lR1 + lR2)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
