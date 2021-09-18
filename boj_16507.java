import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int r,c,q,i,j,x1,y1,x2,y2;
		StringTokenizer st = new StringTokenizer(br.readLine());
		r = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		q = Integer.parseInt(st.nextToken());
		long[][] dp = new long[r+2][c+2];
		for(i=1;i<=r;i++) {
			st = new StringTokenizer(br.readLine());
			for(j=1;j<=c;j++) dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+Integer.parseInt(st.nextToken());
		}
		while(q-->0) {
			st = new StringTokenizer(br.readLine());
			y1 = Integer.parseInt(st.nextToken());
			x1 = Integer.parseInt(st.nextToken());
			y2 = Integer.parseInt(st.nextToken());
			x2 = Integer.parseInt(st.nextToken());
			sb.append((dp[y2][x2]-dp[y1-1][x2]-dp[y2][x1-1]+dp[y1-1][x1-1])/((y2-y1+1)*(x2-x1+1))+"\n");
		}
		System.out.println(sb);
	}
}
