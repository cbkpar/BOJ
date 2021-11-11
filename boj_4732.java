import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String[] arr = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};
        while (true) {
            String str = br.readLine();
            if (str.equals("***")) break;
            StringTokenizer st = new StringTokenizer(str);
            int t = Integer.parseInt(br.readLine()) % 12 + 12;
            sb.append(arr[(convert(st.nextToken()) + t + 12) % 12]);
            while (st.hasMoreTokens()) {
                sb.append(" " + arr[(convert(st.nextToken()) + t) % 12]);
            }
            sb.append("\n");
        }
        System.out.println(sb);
    }

    private static int convert(String str) {
        int tmp = 0;
        if (str.charAt(0) == 'B') tmp += 2;
        if (str.charAt(0) == 'C') tmp += 3;
        if (str.charAt(0) == 'D') tmp += 5;
        if (str.charAt(0) == 'E') tmp += 7;
        if (str.charAt(0) == 'F') tmp += 8;
        if (str.charAt(0) == 'G') tmp += 10;
        if (str.length() == 2) {
            if (str.charAt(1) == 'b') tmp--;
            if (str.charAt(1) == '#') tmp++;
        }
        return tmp % 12;
    }
}
