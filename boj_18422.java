import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,m,i,j,s;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		boolean[][] map = new boolean[n+1][m+1];
		s = 0;
		for(i=1;i<=n;i++) {
			String str = br.readLine();
			for(j=1;j<=m;j++) {
				if(str.charAt(j-1)=='*') {
					map[i][j] = true;
					if(!map[i-1][j]&&!map[i][j-1]) s++;
				}
			}
		}
		System.out.println(s);
	}
}
