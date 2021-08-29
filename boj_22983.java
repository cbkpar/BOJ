import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,m,i,j;
		long ans;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		long[][][] dp = new long[n][m][2];
		for(i=0;i<n;i++) {
			String str = br.readLine();
			for(j=0;j<m;j++) {
				if(str.charAt(j)=='B') {
					dp[i][j][0] = 1;
				}else {
					dp[i][j][1] = 1;
				}
			}
		}
		for(i=1;i<n;i++) {
			for(j=1;j<m;j++) {
				if(dp[i][j][0]==1) {
					dp[i][j][0] = Math.min(dp[i-1][j-1][0],Math.min(dp[i-1][j][1], dp[i][j-1][1]))+1;
				}else {
					dp[i][j][1] = Math.min(dp[i-1][j-1][1],Math.min(dp[i-1][j][0], dp[i][j-1][0]))+1;
				}
			}
		}
		ans = 0;
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				ans += dp[i][j][0];
				ans += dp[i][j][1];
			}
		}
		System.out.println(ans);
	}
}
