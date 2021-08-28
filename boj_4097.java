import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,i,mx;
		while(true) {
			n = Integer.parseInt(br.readLine());
			if(n==0) break;
			int[] dp = new int[n+1];
			for(i=1;i<=n;i++) dp[i] = (dp[i-1]<0?0:dp[i-1]) + Integer.parseInt(br.readLine());
			mx = Integer.MIN_VALUE;
			for(i=1;i<=n;i++) mx = Math.max(mx, dp[i]);
			sb.append(mx+"\n");
		}
		System.out.println(sb);
	}
}
