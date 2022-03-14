import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] arr = new String[5];
        for (int i = 0; i < 5; i++) arr[i] = br.readLine();
        int num = 0;
        int sz = (arr[0].length() / 4) + 1;
        for (int i = 0; i < sz; i++) {
            num *= 10;
            int tmp = convert(arr, i * 4);
            if (tmp == -1) {
                System.out.println("BOOM!!");
                return;
            }
            num += tmp;
        }
        System.out.println(num % 6 == 0 ? "BEER!!" : "BOOM!!");
    }

    private static int convert(String[] str, int pos) {
        int tmp = 0;
        int mxpos = str[0].length();
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 3; j++) {
                tmp <<= 1;
                if (pos + j >= mxpos) continue;
                if (str[i].charAt(pos + j) == '*') tmp++;
            }
        }
        if (tmp == 31599) return 0;
        if (tmp == 4681) return 1;
        if (tmp == 29671) return 2;
        if (tmp == 29647) return 3;
        if (tmp == 23497) return 4;
        if (tmp == 31183) return 5;
        if (tmp == 31215) return 6;
        if (tmp == 29257) return 7;
        if (tmp == 31727) return 8;
        if (tmp == 31695) return 9;
        return -1;
    }
}
