import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int iTotalCost = Integer.parseInt(br.readLine());
        int iN = Integer.parseInt(br.readLine());
        for (int i = 0; i < iN; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int iCost = Integer.parseInt(st.nextToken());
            int iAmount = Integer.parseInt(st.nextToken());
            iTotalCost -= iCost * iAmount;
        }
        if (0 == iTotalCost) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
