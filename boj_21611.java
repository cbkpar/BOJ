import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static ArrayList<Integer> arr = new ArrayList<>();
    static int sz, n, score;
    static boolean chk;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[][] map = new int[n][n];
        int[] dir = {0, 7, 3, 1, 5};
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) map[i][j] = Integer.parseInt(st.nextToken());
        }
        arr.add(-1);
        for (int k = 1; 2 * k + 1 <= n; k++) {
            for (int i = 0; i < 2 * k; i++) arr.add(map[n / 2 - k + 1 + i][n / 2 - k]);
            for (int i = 0; i < 2 * k; i++) arr.add(map[n / 2 + k][n / 2 - k + 1 + i]);
            for (int i = 0; i < 2 * k; i++) arr.add(map[n / 2 + k - 1 - i][n / 2 + k]);
            for (int i = 0; i < 2 * k; i++) arr.add(map[n / 2 - k][n / 2 + k - 1 - i]);
        }
        for (int i = n * n - 1; i >= 1; i--) if (arr.get(i) == 0) arr.remove(i);
        score = 0;
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            int d = dir[Integer.parseInt(st.nextToken())];
            int l = Integer.parseInt(st.nextToken());
            for (int i = l; i >= 1; i--) {
                int k = d * i + 4 * i * (i - 1);
                if (k >= arr.size()) continue;
                arr.remove(k);
            }
            while (true) {
                chk = true;
                bomb();
                if (chk) break;
            }
            copy();
        }
        System.out.println(score);
    }

    private static void bomb() {
        sz = arr.size();
        if (sz == 1) return;
        int cnt = 1;
        int idx = 1;
        Stack<Integer> qcnt = new Stack<>();
        Stack<Integer> qnum = new Stack<>();
        for (int i = 2; i < sz; i++) {
            if (arr.get(idx) == arr.get(i)) {
                cnt++;
            } else {
                if (cnt >= 4) {
                    qcnt.add(cnt);
                    qnum.add(idx);
                }
                cnt = 1;
                idx = i;
            }
        }
        if (cnt >= 4) {
            qcnt.add(cnt);
            qnum.add(idx);
        }
        while (!qcnt.isEmpty()) {
            chk = false;
            int tcnt = qcnt.pop();
            int tidx = qnum.pop();
            score += arr.get(tidx) * tcnt;
            for (int i = 0; i < tcnt; i++) arr.remove(tidx);
        }
    }

    private static void copy() {
        sz = arr.size();
        if (sz == 1) return;
        int cnt = 1;
        int idx = 1;
        Queue<Integer> qcnt = new LinkedList<>();
        Queue<Integer> qnum = new LinkedList<>();
        for (int i = 2; i < sz; i++) {
            if (arr.get(idx) == arr.get(i)) {
                cnt++;
            } else {
                qcnt.add(cnt);
                qnum.add(arr.get(idx));
                cnt = 1;
                idx = i;
            }
        }
        qcnt.add(cnt);
        qnum.add(arr.get(idx));
        sz = Math.min((n * n) / 2, qcnt.size());
        arr.clear();
        arr.add(-1);
        for (int i = 0; i < sz; i++) {
            arr.add(qcnt.poll());
            arr.add(qnum.poll());
        }
    }
}
