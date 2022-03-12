import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;

public class Main {

    static HashSet<String> set = new HashSet<>();
    static boolean[] chk = new boolean[4];
    static String[] str = new String[4];

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < 4; i++) str[i] = br.readLine();
        dfs("",0);
        while (n-- > 0) {
            if (set.contains(br.readLine())) {
                sb.append("YES\n");
            } else {
                sb.append("NO\n");
            }
        }
        System.out.println(sb);
    }

    private static void dfs(String s, int k) {
        set.add(s);
        if (k == 4) return;
        for (int i = 0; i < 4; i++) {
            if (chk[i]) continue;
            chk[i] = true;
            for (int j = 0; j < 6; j++) dfs(s + str[i].charAt(j), k + 1);
            chk[i] = false;
        }
    }
}
