import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i,j,k,left,right,mid,y,x,ny,nx,ans;
		int[] dy = {1,0,-1,0};
		int[] dx = {0,1,0,-1};
		n = Integer.parseInt(br.readLine());
		int[][] map = new int[n][n];
		for(i=0;i<n;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(j=0;j<n;j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		left = -1;
		ans = right = 200;
		while(left<=right) {
			boolean[][] chk = new boolean[n][n];
			mid = (left+right)/2;
			for(k=0;k+mid<=200;k++) {
				if(map[0][0]<k||map[0][0]>k+mid) continue;
				chk = new boolean[n][n];
				Queue<pos> q = new LinkedList<>();
				q.add(new pos(0,0));
				chk[0][0] = true;
				while(!q.isEmpty()) {
					pos p = q.poll();
					y = p.y;
					x = p.x;
					for(i=0;i<4;i++) {
						ny = y + dy[i];
						nx = x + dx[i];
						if(ny<0||ny>n-1||nx<0||nx>n-1) continue;
						if(chk[ny][nx]) continue;
						if(map[ny][nx]<k||map[ny][nx]>k+mid) continue;
						q.add(new pos(ny,nx));
						chk[ny][nx] = true;
					}
				}
				if(chk[n-1][n-1]) break;
			}
			if(chk[n-1][n-1]) {
				ans = Math.min(ans, mid);
				right = mid-1;
			}else {
				left = mid+1;
			}
		}
		System.out.println(ans);
	}
	
	public static class pos {
		int y,x;
		
		public pos(int y, int x) {
			this.y = y;
			this.x = x;
		}
	}
}
