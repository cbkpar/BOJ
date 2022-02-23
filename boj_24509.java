import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n = Integer.parseInt(br.readLine());
		int[][] arr = new int[n][4];
		for (int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int num = Integer.parseInt(st.nextToken());
			for (int j = 0; j < 4; j++)
				arr[num - 1][j] = Integer.parseInt(st.nextToken());
		}
		boolean[] chk = new boolean[n];
		for (int i = 0; i < 4; i++) {
			int mx = -1;
			int tmp = 0;
			for (int j = 0; j < n; j++) {
				if (chk[j])
					continue;
				if (arr[j][i] > mx) {
					mx = arr[j][i];
					tmp = j;
				}
			}
			chk[tmp] = true;
			sb.append((tmp + 1) + " ");
		}
		System.out.println(sb.toString().trim());
	}
}
