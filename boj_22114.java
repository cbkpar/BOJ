import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,k,i,m;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		int[] arr = new int[n];
		st = new StringTokenizer(br.readLine());
		for(i=0;i<n-1;i++) arr[i] = Integer.parseInt(st.nextToken());
		int[][] dp = new int[n][2];
		dp[0][0] = dp[0][1] = 1;
		for(i=0;i<n-1;i++) {
			if(arr[i]<=k) {
				dp[i+1][0] = dp[i][0] + 1;
				dp[i+1][1] = dp[i][1] + 1;
			}else {
				dp[i+1][0] = 1;
				dp[i+1][1] = dp[i][0] + 1;
			}
		}
		m = 0;
		for(i=0;i<n;i++) {
			m = Math.max(m, dp[i][0]);
			m = Math.max(m, dp[i][1]);
		}
		System.out.println(m);
	}
}
