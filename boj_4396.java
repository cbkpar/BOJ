import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n, i, j, p, q, ny, nx;
		n = Integer.parseInt(br.readLine());
		int[][] map = new int[n][n];
		int[][] ans = new int[n][n];
		for (i = 0; i < n; i++) {
			String str = br.readLine();
			for (j = 0; j < n; j++) {
				if (str.charAt(j) == '*')
					map[i][j] = 1;
			}
		}
		boolean chk = false;
		for (i = 0; i < n; i++) {
			String str = br.readLine();
			for (j = 0; j < n; j++) {
				if (str.charAt(j) == '.') {
					ans[i][j] = -1;
					continue;
				}
				if (map[i][j] == 1)
					chk = true;
				for (p = -1; p <= 1; p++) {
					for (q = -1; q <= 1; q++) {
						if (p == 0 & q == 0)
							continue;
						ny = i + p;
						nx = j + q;
						if (ny < 0 || ny >= n || nx < 0 || nx >= n)
							continue;
						ans[i][j] += map[ny][nx];
					}
				}
			}
		}
		if(chk) {
			for(i=0;i<n;i++) {
				for(j=0;j<n;j++) {
					if(map[i][j]==1) ans[i][j] = -2;
				}
			}
		}
		for(i=0;i<n;i++) {
			for(j=0;j<n;j++) {
				if(ans[i][j]==-1) {
					sb.append(".");
				}else if(ans[i][j]==-2) {
					sb.append("*");
				}else {
					sb.append(ans[i][j]);
				}
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}
}
