import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	int n,t,i,j,k,l,ans;
    	String str;
    	n = Integer.parseInt(br.readLine());
    	int[][] dp = new int[n+2][n+2];
    	t = 0;
    	while((str=br.readLine())!=null){
    		StringTokenizer st = new StringTokenizer(str);
    		while(st.hasMoreTokens()) {
    			dp[t/n+1][t%n+1] = Integer.parseInt(st.nextToken());
    			t++;
    		}
    	}
    	for(i=1;i<=n;i++) {
    		for(j=1;j<=n;j++) {
    			dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
    		}
    	}
    	ans = Integer.MIN_VALUE;
    	for(i=1;i<=n;i++) {
    		for(j=1;j<=n;j++) {
    			for(k=i;k<=n;k++) {
    				for(l=j;l<=n;l++) {
    					ans = Math.max(ans, dp[k][l]-dp[i-1][l]-dp[k][j-1]+dp[i-1][j-1]);
    				}
    			}
    		}
    	}
    	System.out.println(ans);
    }
}
