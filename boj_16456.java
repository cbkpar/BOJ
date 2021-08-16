import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i;
		n = Integer.parseInt(br.readLine());
		if(n<=2) {
			System.out.println(1);
			return;
		}
		int[] dp = new int[n+1];
		dp[1] =	dp[2] = 1;
		dp[3] = 2;
		for(i=4;i<=n;i++) dp[i] = (dp[i-1]+dp[i-3])%1000000009;
		System.out.println(dp[n]);
	}
}
