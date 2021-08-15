import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int[][] map = new int[5][5];
	static int[] dy = {1,0,-1,0};
	static int[] dx = {0,1,0,-1};
	static boolean[] chk = new boolean[1000000];
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int i,j,ans;
		for(i=0;i<5;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(j=0;j<5;j++) map[i][j] = Integer.parseInt(st.nextToken());
		}
		for(i=0;i<5;i++) for(j=0;j<5;j++) dfs(i,j,0,0);
		ans = 0;
		for(i=0;i<=999999;i++) if(chk[i]) ans++;
		System.out.println(ans);
	}
	
	public static void dfs(int y, int x, int k, int n) {
		if(k==6) {
			chk[n] = true;
			return;
		}
		for(int i=0;i<4;i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny<0||ny>4||nx<0||nx>4) continue;
			dfs(ny,nx,k+1,n*10+map[ny][nx]);
		}
	}
}
