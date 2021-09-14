import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i,j,t;
		n = Integer.parseInt(br.readLine());
		int[][] dp = new int[n][n];
		for(i=0;i<n;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(j=0;j<n;j++) dp[i][j] = trans(st.nextToken().charAt(0));
		}
		for(i=n-1;i>=0;i--) {
			for(j=0;j<n;j++) {
				t = 0;
				if(i!=n-1) t = Math.max(t, dp[i+1][j]);
				if(j!=0) t = Math.max(t, dp[i][j-1]);
				dp[i][j] += t;
			}
		}
		System.out.println(dp[0][n-1]); 
	}
	
	public static int trans(char c) {
		if(c>='2'&&c<='9') return c-'0';
		if(c=='A') return 1;
		if(c=='T') return 10;
		if(c=='J') return 11;
		if(c=='Q') return 12;
		if(c=='K') return 13;
		return 0;
	}
}
