import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int iX = Integer.parseInt(st.nextToken());
        int iY = Integer.parseInt(st.nextToken());
        if (iX <= iY) {
            System.out.println(iY - iX);
        } else {
            System.out.println(iX + iY);
        }
    }
}
