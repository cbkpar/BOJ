import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        if(n==0){
            System.out.println("NO");
            return;
        }
        while (n > 0) {
            if (n % 3 == 2) {
                System.out.println("NO");
                return;
            }
            n /= 3;
        }
        System.out.println("YES");
    }
}
