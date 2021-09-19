import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringBuilder sb = new StringBuilder();
    	int n,i,j,t;
    	int[][] dp = new int[2001][2001];
    	dp[0][0] = 0;
    	for(i=1;i<=2000;i++) {
    		for(j=0;j<i;j++) dp[i][j] = dp[i-1][j];
    		dp[i][i] = (dp[i-1][i] + dp[i-1][0] + 1)%100999;
    		for(j=i+1;j<=2000;j++) dp[i][j] = (dp[i-1][j] + dp[i-1][j-i])%100999;
    	}
    	n = Integer.parseInt(br.readLine());
    	while(n-->0) {
    		t = Integer.parseInt(br.readLine());
    		sb.append(dp[t][t]+"\n");
    	}
    	System.out.println(sb);
    }
}
