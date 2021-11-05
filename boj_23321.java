import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder[] sb = new StringBuilder[5];
        for (int i = 0; i < 5; i++) sb[i] = new StringBuilder();
        String[] arr = new String[5];
        for (int i = 0; i < 5; i++) {
            arr[i] = br.readLine();
        }
        int sz = arr[0].length();
        for (int i = 0; i < sz; i++) {
            if (arr[1].charAt(i) == 'o') {
                sb[0].append('o');
                sb[1].append('w');
                sb[2].append('l');
                sb[3].append('n');
                sb[4].append('.');
            } else if (arr[1].charAt(i) == 'w') {
                sb[0].append('.');
                sb[1].append('o');
                sb[2].append('m');
                sb[3].append('l');
                sb[4].append('n');
            } else {
                sb[0].append('.');
                sb[1].append('.');
                sb[2].append('o');
                sb[3].append('L');
                sb[4].append('n');
            }
        }
        System.out.println(sb[0] + "\n" + sb[1] + "\n" + sb[2] + "\n" + sb[3] + "\n" + sb[4]);
    }
}
