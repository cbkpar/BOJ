import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int s = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        int[] arr = new int[s];
        for (int i = 0; i < s; i++) arr[i] = Integer.parseInt(br.readLine());
        long left = 1;
        long right = 1000000001;
        long mx = 0;
        while (left <= right) {
            long mid = (left + right) / 2;
            long cnt = 0;
            for (int i = 0; i < s; i++) cnt += arr[i] / mid;
            if (cnt >= c) {
                mx = Math.max(mx, mid);
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        long ans = -c*mx;
        for (int i = 0; i < s; i++) ans += arr[i];
        System.out.println(ans);
    }
}
