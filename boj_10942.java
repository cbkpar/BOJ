import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,m,i,j,s,e;
		n = Integer.parseInt(br.readLine());
		int[] arr = new int[n+1];
		int[][] dp = new int[n+1][n+1];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(i=1;i<=n;i++) arr[i] = Integer.parseInt(st.nextToken());
		for(i=1;i<=n;i++) dp[i][i] = 1;
		for(i=1;i<n;i++) if(arr[i]==arr[i+1]) dp[i][i+1] = 1;
		for(i=2;i<n;i++) for(j=1;i+j<=n;j++) if(arr[j]==arr[i+j]) dp[j][i+j] = dp[j+1][i+j-1];
		m = Integer.parseInt(br.readLine());
		while(m-->0) {
			st = new StringTokenizer(br.readLine());
			s = Integer.parseInt(st.nextToken());
			e = Integer.parseInt(st.nextToken());
			sb.append(dp[s][e]+"\n");
		}
		System.out.println(sb);
	}
}
