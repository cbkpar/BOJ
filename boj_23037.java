import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] arr = {0, 1, 32, 243, 1024, 3125, 7776, 16807, 32768, 59049};
        int n, s, i;
        s = 0;
        String str = br.readLine();
        for (i = 0; i < 5; i++) {
            s += arr[str.charAt(i)-'0'];
        }
        System.out.println(s);
    }
}
