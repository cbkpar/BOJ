import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,s,t,i,ans;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		s = Integer.parseInt(st.nextToken());
		ans = 0;
		int[] dp = new int[1000001];
		while(n-->0) {
			t = Integer.parseInt(br.readLine());
			dp[t]++;
		}
		for(i=1;i<=1000000;i++) dp[i] += dp[i-1];
		for(i=1;i<=s;i++) {
			t = Math.min(s-i, i-1);
			ans += dp[t]*(dp[i]-dp[i-1]);
			if(2*i<=s&&(dp[i]-dp[i-1])>1) ans += ((dp[i]-dp[i-1]))*((dp[i]-dp[i-1])-1)/2; 
		}
		System.out.println(ans);
	}
}
