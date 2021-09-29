import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static boolean[][] chk;
	static boolean flag;
	static int k, n;
	static int[] arr;
	static StringBuilder sb = new StringBuilder();

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int f, s, e;
		StringTokenizer st = new StringTokenizer(br.readLine());
		k = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(st.nextToken());
		f = Integer.parseInt(st.nextToken());
		chk = new boolean[n + 1][n + 1];
		arr = new int[k];
		while (f-- > 0) {
			st = new StringTokenizer(br.readLine());
			s = Integer.parseInt(st.nextToken());
			e = Integer.parseInt(st.nextToken());
			chk[s][e] = true;
			chk[e][s] = true;
		}
		dfs(0, 0);
		if(!flag) sb.append("-1");
		System.out.println(sb);
	}

	public static void dfs(int num, int cnt) {
		if (flag) return;
		if (cnt == k) {
			flag = true;
			for (int i = 0; i < k; i++) sb.append(arr[i] + "\n");
			return;
		}
		for (int i = num; i <= n; i++) {
			boolean ch = true;
			for (int j = 0; j < cnt; j++) {
				if (!chk[i][arr[j]]) {
					ch = false;
					break;
				}
			}
			if (ch) {
				arr[cnt] = i;
				dfs(i + 1, cnt + 1);
			}
		}
	}
}
