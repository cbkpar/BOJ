import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String str;
        while ((str = br.readLine()) != null) {
            StringTokenizer st = new StringTokenizer(str);
            int iN = Integer.parseInt(st.nextToken());
            int iS = Integer.parseInt(st.nextToken());
            sb.append((iS / (iN + 1)) + "\n");
        }
        System.out.println(sb);
    }
}
