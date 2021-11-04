import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        ArrayList<Long> A = new ArrayList<>();
        ArrayList<Long> B = new ArrayList<>();
        long ans = 0;
        for (int i = 0; i < n; i++) {
            long t = Long.parseLong(br.readLine());
            if (t < 1) {
                A.add(t);
            } else if (t == 1) {
                ans++;
            } else {
                B.add(t);
            }
        }
        Collections.sort(A);
        Collections.sort(B, Collections.reverseOrder());
        for (int i = 0; i < A.size(); i += 2) {
            long t = A.get(i);
            if (i + 1 < A.size()) t *= A.get(i + 1);
            ans += t;
        }
        for (int i = 0; i < B.size(); i += 2) {
            long t = B.get(i);
            if (i + 1 < B.size()) t *= B.get(i + 1);
            ans += t;
        }
        System.out.println(ans);
    }
}
