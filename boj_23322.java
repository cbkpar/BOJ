import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int s = 0;
        int cnt = 0;
        int standard = Integer.parseInt(st.nextToken());
        for (int i = 1; i < n; i++) {
            int tmp = Integer.parseInt(st.nextToken());
            if (tmp != standard) {
                s += tmp - standard;
                cnt++;
            }
        }
        System.out.println(s + " " + cnt);
    }
}
