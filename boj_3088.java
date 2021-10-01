import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, a, b, c, t;
        n = Integer.parseInt(br.readLine());
        t = 0;
        boolean[] chk = new boolean[10000001];
        while (n-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());
            if(!chk[a]&&!chk[b]&&!chk[c]) t++;
            chk[a] = chk[b] = chk[c] = true;
        }
        System.out.println(t);
    }
}
