import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int[][] map;
	static int[][] cost;
	static boolean[][] chk;
	static int n,ans;
	static int[] dy = {0,0,1,0,-1};
	static int[] dx = {0,1,0,-1,0};
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int i,j,k;
		n = Integer.parseInt(br.readLine());
		map = new int[n][n];
		cost = new int[n][n];
		chk = new boolean[n][n];
		for(i=0;i<n;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(j=0;j<n;j++) map[i][j] = Integer.parseInt(st.nextToken());
		}
		for(i=1;i<n-1;i++) {
			for(j=1;j<n-1;j++) {
				for(k=0;k<5;k++) {
					cost[i][j] += map[i+dy[k]][j+dx[k]];
				}
			}
		}
		ans = Integer.MAX_VALUE;
		brute(0,0);
		System.out.println(ans);
	}
	
	public static void brute(int cnt, int sum) {
		if(sum>=ans) return;
		if(cnt==3) {
			ans = sum;
			return;
		}
		for(int i=1;i<n-1;i++) {
			for(int j=1;j<n-1;j++) {
				boolean isvisit = false;
				for(int k=0;k<5;k++) {
					if(chk[i+dy[k]][j+dx[k]]) {
						isvisit = true;
						break;
					}
				}
				if(!isvisit) {
					for(int k=0;k<5;k++) chk[i+dy[k]][j+dx[k]] = true;
					brute(cnt+1,sum+cost[i][j]);
					for(int k=0;k<5;k++) chk[i+dy[k]][j+dx[k]] = false;
				}
			}
		}
	}
}
