import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        if(!str.contains("x")){
            System.out.println("0");
            return;
        }
        if (str.charAt(0) == 'x') {
            System.out.println("1");
        } else if (str.charAt(0) == '-') {
            if (str.charAt(1) == 'x') {
                System.out.println("-1");
            } else {
                StringTokenizer st = new StringTokenizer(str, "x");
                System.out.println(st.nextToken());
            }
        } else {
            StringTokenizer st = new StringTokenizer(str, "x");
            System.out.println(st.nextToken());
        }
    }
}
