import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int iT = Integer.parseInt(br.readLine());
        while(iT-->0)
        {
            StringTokenizer st = new StringTokenizer(br.readLine(), ",");
            boolean bSpace = false;
            while(st.hasMoreTokens())
            {
                int iNum = Integer.parseInt(st.nextToken().trim());
                if(iNum%4==0) {
                    if (bSpace) sb.append(" ");
                    sb.append(iNum);
                    bSpace = true;
                }
            }
            sb.append("\n");
        }
        System.out.println(sb);
    }
}
