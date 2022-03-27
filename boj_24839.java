import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        for (int i = 1; i <= T; i++) {
            String I = br.readLine();
            String P = br.readLine();
            sb.append("Case #" + i + ": " + chk(I, P) + "\n");
        }
        System.out.println(sb);
    }

    private static String chk(String I, String P) {
        int Isz = I.length();
        int Psz = P.length();
        if (Isz > Psz) return "IMPOSSIBLE";
        int Iidx = 0;
        int cnt = 0;
        for (int i = 0; i < Psz; i++) {
            if (Iidx == Isz) {
                cnt += Psz - i;
                break;
            }
            if (I.charAt(Iidx) == P.charAt(i)) {
                Iidx++;
            } else {
                cnt++;
            }
        }
        if (Iidx == Isz) return Integer.toString(cnt);
        return "IMPOSSIBLE";
    }
}
