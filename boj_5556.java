import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int iN = Integer.parseInt(br.readLine());
        int iK = Integer.parseInt(br.readLine());
        while (iK-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int iA = Integer.parseInt(st.nextToken());
            int iB = Integer.parseInt(st.nextToken());
            if (iA >= iN / 2) iA = iN - iA + 1;
            if (iB >= iN / 2) iB = iN - iB + 1;
            int iC = Math.min(iA, iB) % 3;
            if (iC == 0) iC = 3;
            sb.append(iC + "\n");
        }
        System.out.println(sb);
    }
}
