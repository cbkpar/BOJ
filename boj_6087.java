import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,m,i,j,k,ny,nx,y,x,sz,t;
		int[] dy = {1,0,-1,0};
		int[] dx = {0,1,0,-1};
		StringTokenizer st = new StringTokenizer(br.readLine());
		m = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(st.nextToken());
		int[][] map = new int[n][m];
		boolean[][] visited = new boolean[n][m];
		y = x = 0;
		for(i=0;i<n;i++) {
			String str = br.readLine();
			for(j=0;j<m;j++) {
				if(str.charAt(j)=='C') {
					map[i][j] = 2;
					y = i;
					x = j;
				}else if(str.charAt(j)=='*') {
					map[i][j] = 1;
				}
			}
		}
		Queue<pos> q = new LinkedList<>();
		q.add(new pos(y,x));
		map[y][x] = 0;
		t = -1;
		while(!q.isEmpty()) {
			sz = q.size();
			for(i=0;i<sz;i++) {
				pos p = q.poll();
				if(map[p.y][p.x]==2) {
					System.out.println(t);
					return;
				}
				for(j=0;j<4;j++) {
					k = 1;
					while(true) {
						ny = p.y + dy[j]*k;
						nx = p.x + dx[j]*k;
						if(ny<0||ny>n-1||nx<0||nx>m-1||map[ny][nx]==1) break;
						if(!visited[ny][nx]) {
							visited[ny][nx] = true;
							q.add(new pos(ny,nx));
						}
						k++;
					}
				}
			}
			t++;
		}
	}
	
	public static class pos {
		int y,x;
		
		public pos(int y, int x) {
			this.y = y;
			this.x = x;
		}
	}
}
