import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, i, j, k, s, sz, g, ty, tx, a, b;
        n = Integer.parseInt(br.readLine());
        ArrayList<pos> arr = new ArrayList<>();
        for (i = 0; i < n; i++) {
            String str = br.readLine();
            for (j = 0; j < n; j++) if (str.charAt(j) != '.') arr.add(new pos(i, j));
        }
        s = 0;
        sz = arr.size();
        for (i = 0; i < sz; i++) {
            for (j = i + 1; j < sz; j++) {
                for (k = j + 1; k < sz; k++) {
                    a = Math.abs(arr.get(j).y - arr.get(i).y);
                    b = Math.abs(arr.get(j).x - arr.get(i).x);
                    if (a == 0) {
                        if (arr.get(k).y == arr.get(i).y) s++;
                        continue;
                    }
                    if (b == 0) {
                        if (arr.get(k).x == arr.get(i).x) s++;
                        continue;
                    }
                    if (b > a) {
                        g = gcd(a, b);
                    } else {
                        g = gcd(b, a);
                    }
                    ty = (arr.get(j).y - arr.get(i).y) / g;
                    tx = (arr.get(j).x - arr.get(i).x) / g;
                    if ((arr.get(k).y - arr.get(i).y) * tx == (arr.get(k).x - arr.get(i).x) * ty) s++;
                }
            }
        }
        System.out.println(s);
    }

    public static int gcd(int a, int b) {
        if (b % a == 0) return a;
        return gcd(b % a, a);
    }
}

class pos {
    int y, x;

    public pos(int y, int x) {
        this.y = y;
        this.x = x;
    }
}
