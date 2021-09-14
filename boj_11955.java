import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int r,s,k,i,j,mx,tr,ts,tmp;
		StringTokenizer st = new StringTokenizer(br.readLine());
		r = Integer.parseInt(st.nextToken());
		s = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		int[][] dp = new int[r+2][s+2];
		char[][] ch = new char[r][s];
		for(i=0;i<r;i++) {
			ch[i] = br.readLine().toCharArray();
			for(j=0;j<s;j++) if(ch[i][j]=='*') dp[i+1][j+1] = 1;
		}
		for(i=1;i<=r;i++) {
			for(j=1;j<=s;j++) {
				dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
			}
		}
		tr = ts = mx = 0;
		for(i=1;i<=r-k+1;i++) {
			for(j=1;j<=s-k+1;j++) {
				tmp = dp[i+k-2][j+k-2] - dp[i+k-2][j] - dp[i][j+k-2] + dp[i][j];
				if(tmp>mx) {
					mx = tmp;
					tr = i-1;
					ts = j-1;
				}
			}
		}
		for(i=ts+1;i<ts+k-1;i++) {
			ch[tr][i] = '-';
			ch[tr+k-1][i] = '-';
		}
		for(i=tr+1;i<tr+k-1;i++) {
			ch[i][ts] = '|';
			ch[i][ts+k-1] = '|';
		}
		ch[tr][ts] = ch[tr][ts+k-1] = ch[tr+k-1][ts] = ch[tr+k-1][ts+k-1] = '+';
		sb.append(mx+"\n");
		for(i=0;i<r;i++) {
			for(j=0;j<s;j++) {
				sb.append(ch[i][j]);
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}
}
