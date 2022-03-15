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
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int l = Integer.parseInt(st.nextToken());
        ArrayList<pond> arr = new ArrayList<>();
        while (n-- > 0) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken()) - 1;
            arr.add(new pond(s, e));
        }
        Collections.sort(arr, new Comparator<pond>() {
            @Override
            public int compare(pond o1, pond o2) {
                if (o1.s != o2.s) return o1.s - o2.s;
                return o2.e - o1.e;
            }
        });
        int block = -1;
        int cnt = 0;
        for (pond p : arr) {
            if (p.e <= block) continue;
            if (block >= p.s) {
                int tmp = p.e - block;
                cnt += tmp / l;
                block += (tmp / l) * l;
                if (tmp % l != 0) {
                    cnt++;
                    block += l;
                }
            } else {
                int tmp = p.e - p.s + 1;
                cnt += tmp / l;
                block = p.s + (tmp / l) * l - 1;
                if (tmp % l != 0) {
                    cnt++;
                    block += l;
                }
            }
        }
        System.out.println(cnt);
    }
}

class pond {
    int s;
    int e;

    public pond(int s, int e) {
        this.s = s;
        this.e = e;
    }
}
