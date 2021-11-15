import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        ArrayList<Integer>[] num = new ArrayList[n + 1];
        for (int i = 0; i < n; i++) num[i] = new ArrayList<>();
        int[] pos = new int[n];
        int[] N = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        ArrayList<Integer> arr = new ArrayList<>();
        arr.add(-1000000001);
        for (int i = 0; i < n; i++) {
            N[i] = Integer.parseInt(st.nextToken());
            int t = N[i];
            if (t > arr.get(arr.size() - 1)) {
                pos[i] = arr.size() - 1;
                arr.add(t);
            } else {
                int left = 0;
                int right = arr.size() - 1;
                while (left < right) {
                    int mid = (left + right) / 2;
                    if (arr.get(mid) < t) {
                        left = mid + 1;
                    } else {
                        right = mid;
                    }
                }
                pos[i] = left - 1;
                arr.set(left, t);
            }
        }
        int sz = arr.size() - 1;
        ArrayList<Integer>[] dp = new ArrayList[sz];
        for (int i = 0; i < sz; i++) {
            dp[i] = new ArrayList<>();
            dp[i].add(0);
        }
        for (int i = n - 1; i >= 0; i--) {
            if (pos[i] == sz - 1) {
                num[pos[i]].add(N[i]);
                dp[pos[i]].add((dp[pos[i]].get(dp[pos[i]].size() - 1) + 1) % 1000000007);
            } else {
                int left = 0;
                int right = num[pos[i] + 1].size();
                while (left < right) {
                    int mid = (left + right) / 2;
                    if (num[pos[i] + 1].get(mid) <= N[i]) {
                        left = mid + 1;
                    } else {
                        right = mid;
                    }
                }
                num[pos[i]].add(N[i]);
                int tmp = dp[pos[i] + 1].get(dp[pos[i] + 1].size() - 1) - dp[pos[i] + 1].get(left);
                if (tmp < 0) tmp += 1000000007;
                dp[pos[i]].add((dp[pos[i]].get(dp[pos[i]].size() - 1) + tmp) % 1000000007);
            }
        }
        System.out.println(sz + " " + dp[0].get(dp[0].size() - 1));
    }
}
