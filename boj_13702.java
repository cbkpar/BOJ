import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		long[] arr = new long[n];
		for (int i = 0; i < n; i++)
			arr[i] = Integer.parseInt(br.readLine());
		long left = 0;
		long right = Long.MAX_VALUE - 1;
		long ans = 0;
		while (left <= right) {
			long mid = (left + right) / 2;
			if (mid == 0) break;
			int tmp = 0;
			for (int i = 0; i < n; i++)
				tmp += arr[i] / mid;
			if (tmp >= k) {
				ans = Math.max(ans, mid);
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
		System.out.println(ans);
	}
}
