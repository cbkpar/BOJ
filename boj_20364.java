import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());
        HashSet<Integer> set = new HashSet<>();
        while (q-- > 0) {
            int x = Integer.parseInt(br.readLine());
            int t = x;
            int other = 0;
            while (x > 0) {
                if (set.contains(x)) other = x;
                x /= 2;
            }
            sb.append(other + "\n");
            if (other == 0) set.add(t);
        }
        System.out.println(sb);
    }
}
