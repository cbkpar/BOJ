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
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] arr = new int[m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) arr[j] += Integer.parseInt(st.nextToken());
        }
        ArrayList<area> list = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            list.add(new area(i + 1, arr[i]));
        }
        Collections.sort(list, new Comparator<area>() {
            @Override
            public int compare(area o1, area o2) {
                if (o1.cnt != o2.cnt) return o2.cnt - o1.cnt;
                return o1.n - o2.n;
            }
        });
        for (int i = 0; i < m; i++) sb.append(list.get(i).n + " ");
        System.out.println(sb.toString().trim());
    }
}

class area {
    int n, cnt;

    public area(int n, int cnt) {
        this.n = n;
        this.cnt = cnt;
    }
}
