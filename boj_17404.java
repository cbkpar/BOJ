import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i,t,m;
		n = Integer.parseInt(br.readLine());
		int[][] dp = new int[n][9];
		dp[0][0] = dp[0][1] = 1000000000;
		dp[0][3] = dp[0][5] = 1000000000;
		dp[0][7] = dp[0][8] = 1000000000;
		StringTokenizer st = new StringTokenizer(br.readLine());
		dp[0][6] = Integer.parseInt(st.nextToken());
		dp[0][4] = Integer.parseInt(st.nextToken());
		dp[0][2] = Integer.parseInt(st.nextToken());
		for(i=1;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			t = Integer.parseInt(st.nextToken());
			dp[i][0] = Math.min(dp[i-1][1], dp[i-1][2]) + t;
			dp[i][3] = Math.min(dp[i-1][4], dp[i-1][5]) + t;
			dp[i][6] = Math.min(dp[i-1][7], dp[i-1][8]) + t;
			t = Integer.parseInt(st.nextToken());
			dp[i][1] = Math.min(dp[i-1][0], dp[i-1][2]) + t;
			dp[i][4] = Math.min(dp[i-1][3], dp[i-1][5]) + t;
			dp[i][7] = Math.min(dp[i-1][6], dp[i-1][8]) + t;
			t = Integer.parseInt(st.nextToken());
			dp[i][2] = Math.min(dp[i-1][0], dp[i-1][1]) + t;
			dp[i][5] = Math.min(dp[i-1][3], dp[i-1][4]) + t;
			dp[i][8] = Math.min(dp[i-1][6], dp[i-1][7]) + t;
		}
		dp[n-1][2] = 1000000000;
		dp[n-1][4] = 1000000000;
		dp[n-1][6] = 1000000000;
		m = Integer.MAX_VALUE;
		for(i=0;i<9;i++) m = Math.min(m, dp[n-1][i]);
		System.out.println(m);
	}
}
