import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        ArrayList<Integer> people = new ArrayList<>();
        boolean[] hamberger = new boolean[n];
        String str = br.readLine();
        int sz = str.length();
        for (int i = 0; i < sz; i++) {
            if (str.charAt(i) == 'H') {
                hamberger[i] = true;
            } else {
                people.add(i);
            }
        }
        int mx = 0;
        for (int t : people) {
            for (int i = t - k; i <= t + k; i++) {
                if (i < 0 || i >= n) continue;
                if (hamberger[i]) {
                    mx++;
                    hamberger[i] = false;
                    break;
                }
            }
        }
        System.out.println(mx);
    }
}
