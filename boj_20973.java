import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        String hum = br.readLine();
        int cnt = 0;
        int num = 0;
        int sz = str.length();
        while (true) {
            cnt++;
            for (int i = 0; i < sz; i++) {
                if (str.charAt(i) == hum.charAt(num)) {
                    num++;
                    if (num == hum.length()) break;
                }
            }
            if (num == hum.length()) break;
        }
        System.out.println(cnt);
    }
}
