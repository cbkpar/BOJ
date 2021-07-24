import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,m,i,j,mx;
		while(true) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			if(n==0&&m==0) break;
			int[][] map = new int[n+1][m+1];
			for(i=1;i<=n;i++) {
				st = new StringTokenizer(br.readLine());
				for(j=1;j<=m;j++) if(Integer.parseInt(st.nextToken())==1) map[i][j] = Math.min(map[i-1][j-1], Math.min(map[i-1][j], map[i][j-1]))+1;
			}
			mx = 0;
			for(i=1;i<=n;i++) for(j=1;j<=m;j++) mx = Math.max(mx,map[i][j]);
			sb.append(mx+"\n");
		}
		System.out.println(sb);
	}
}
