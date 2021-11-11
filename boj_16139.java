import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String str = br.readLine();
        int sz = str.length();
        int[][] presum = new int[sz + 1][26];
        for (int i = 1; i <= sz; i++) {
            for (int j = 0; j < 26; j++) presum[i][j] = presum[i - 1][j];
            presum[i][str.charAt(i - 1) - 'a']++;
        }
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int c = st.nextToken().charAt(0) - 'a';
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken()) + 1;
            sb.append((presum[e][c] - presum[s][c]) + "\n");
        }
        System.out.println(sb);
    }
}
