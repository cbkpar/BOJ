import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,c,i,j,m,p,q,r,s,ans;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		int[][] dp = new int[n+1][c+1];
		for(i=1;i<=n;i++) {
			st = new StringTokenizer(br.readLine());
			for(j=1;j<=c;j++) {
				dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + Integer.parseInt(st.nextToken());
			}
		}
		m = Integer.parseInt(br.readLine());
		while(m-->0) {
			st = new StringTokenizer(br.readLine());
			p = Integer.parseInt(st.nextToken())-1;
			q = Integer.parseInt(st.nextToken())-1;
			r = Integer.parseInt(st.nextToken());
			s = Integer.parseInt(st.nextToken());
			ans = dp[r][s]-dp[p][s]-dp[r][q]+dp[p][q];
			sb.append(ans+"\n");
		}
		System.out.println(sb);
	}
}
