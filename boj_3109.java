import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static boolean[][] map;
	static int n,m,ans;
	static int[] dy = {-1,0,1};
	static boolean chk;
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int i,j;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		map = new boolean[n][m];
		for(i=0;i<n;i++) {
			String str = br.readLine();
			for(j=0;j<m;j++) if(str.charAt(j)=='x') map[i][j] = true;
		}
		ans = 0;
		for(i=0;i<n;i++) {
			chk = false;
			if(!map[i][0]) {
				map[i][0] = true;
				dfs(i,0);
				map[i][0] = false;
			}
		}
		System.out.println(ans);
	}
	
	public static void dfs(int y, int x) {
		if(x==m-1) {
			ans++;
			chk = true;
			return;
		}
		for(int i=0;i<3;i++) {
			int ny = y + dy[i];
			if(ny<0||ny>n-1) continue;
			if(!map[ny][x+1]) {
				map[ny][x+1] = true;
				dfs(ny,x+1);
				if(chk) return;
			}
		}
	}
}
