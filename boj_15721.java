import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int a = Integer.parseInt(br.readLine());
        int t = Integer.parseInt(br.readLine());
        int c = Integer.parseInt(br.readLine());
        int k = 4;
        int num = -1;
        while (true) {
            if (t <= k) {
                if (t == 1) {
                    num += 1 + c;
                    break;
                } else if (t == 2) {
                    num += 3 + c;
                    break;
                } else {
                    if (c == 0) {
                        num += t + 2;
                        break;
                    } else {
                        num += t + k;
                        break;
                    }
                }

            } else {
                num += k * 2;
                t -= k;
                k++;
            }
        }
        System.out.println(num % a);
    }
}
