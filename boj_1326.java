import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int s = Integer.parseInt(st.nextToken()) - 1;
        int e = Integer.parseInt(st.nextToken()) - 1;
        Queue<Integer> q = new LinkedList<>();
        q.add(s);
        boolean[] chk = new boolean[n];
        chk[s] = true;
        int cnt = 0;
        while (!q.isEmpty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int p = q.poll();
                if (p == e) {
                    System.out.println(cnt);
                    return;
                }
                for (int j = p - arr[p]; j >= 0; j -= arr[p]) {
                    if (chk[j]) continue;
                    chk[j] = true;
                    q.add(j);
                }
                for (int j = p + arr[p]; j < n; j += arr[p]) {
                    if (chk[j]) continue;
                    chk[j] = true;
                    q.add(j);
                }
            }
            cnt++;
        }
        System.out.println("-1");
    }
}
