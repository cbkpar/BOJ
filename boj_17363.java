import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        HashMap<Character, Character> map = new HashMap<>();
        map.put('.', '.');
        map.put('O', 'O');
        map.put('-', '|');
        map.put('|', '-');
        map.put('/', '\\');
        map.put('\\', '/');
        map.put('^', '<');
        map.put('<', 'v');
        map.put('v', '>');
        map.put('>', '^');
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        String[] str = new String[n];
        for (int i = 0; i < n; i++) str[i] = br.readLine();
        for (int i = m - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                sb.append(map.get(str[j].charAt(i)));
            }
            sb.append("\n");
        }
        System.out.println(sb);
    }
}
