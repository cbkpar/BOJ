import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String key = br.readLine();
        char[] keyarr = key.toCharArray();
        Arrays.sort(keyarr);
        String code = br.readLine();
        int sz = key.length();
        int row = code.length() / sz;
        ArrayList<co> arr = new ArrayList<>();
        for (int i = 0; i < sz; i++) {
            arr.add(new co(keyarr[i], code.substring(i * row, i * row + row)));
        }
        boolean[] chk = new boolean[sz];
        int[][] map = new int[row][sz];
        Collections.sort(arr, new Comparator<co>() {
            @Override
            public int compare(co o1, co o2) {
                return o1.ch - o2.ch;
            }
        });
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                if (!chk[j] && (arr.get(i).ch == key.charAt(j))) {
                    chk[j] = true;
                    for (int k = 0; k < row; k++) map[k][j] = arr.get(i).str.charAt(k);
                    break;
                }
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < sz; j++) {
                sb.append((char) map[i][j]);
            }
        }
        System.out.println(sb);
    }
}

class co {
    int ch;
    String str;

    public co(int ch, String str) {
        this.ch = ch;
        this.str = str;
    }
}
