import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        ArrayList<dot> arr = new ArrayList<>();
        for (int i = 1; i <= n * 3; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            arr.add(new dot(x, y, i));
        }
        Collections.sort(arr, new Comparator<dot>() {
            @Override
            public int compare(dot o1, dot o2) {
                if (o1.x != o2.x) return o1.x - o2.x;
                return o1.y - o2.y;
            }
        });
        for (int i = 0; i < 3 * n; i += 3) {
            sb.append(arr.get(i).n + " " + arr.get(i + 1).n + " " + arr.get(i + 2).n + "\n");
        }
        System.out.println(sb);
    }
}

class dot {
    int x, y, n;

    public dot(int x, int y, int n) {
        this.x = x;
        this.y = y;
        this.n = n;
    }
}
