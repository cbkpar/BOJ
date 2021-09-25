import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int sz, n, i, j, ta, tb, s;
        ArrayList<Integer> arr = new ArrayList<>();
        StringTokenizer st = new StringTokenizer(br.readLine());
        while (st.hasMoreTokens()) arr.add(Integer.parseInt(st.nextToken()));
        sz = arr.size();
        n = Integer.parseInt(br.readLine());
        Collections.sort(arr);
        ta = tb = -1;
        s = 0;
        for (i = 0; i < sz - 1; i++) {
            for (j = i + 1; j < sz; j++) {
                if (arr.get(i) + arr.get(j) == n) {
                    if (arr.get(i) != ta && arr.get(j) != tb) {
                        s++;
                        ta = arr.get(i);
                        tb = arr.get(j);
                        sb.append(ta + " " + tb + "\n");
                    }
                }
            }
        }
        System.out.println(sb + "" + s);
    }
}
