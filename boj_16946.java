import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,m,i,j,k,s,ny,nx;
		int[] dy = {1,0,-1,0};
		int[] dx = {0,1,0,-1};
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		boolean[][] map = new boolean[n][m];
		boolean[][] visited = new boolean[n][m];
		int[][] ans = new int[n][m];
		for(i=0;i<n;i++) {
			String str = br.readLine();
			for(j=0;j<m;j++) {
				ans[i][j] = str.charAt(j)-'0';
				if(ans[i][j]==1) map[i][j] = true;
			}
		}
		Queue<pos> q = new LinkedList<>();
		Queue<pos> wall = new LinkedList<>();
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				if(!map[i][j]&&!visited[i][j]) {
					q.add(new pos(i,j));
					visited[i][j] = true;
					s = 0;
					while(!q.isEmpty()) {
						pos p = q.poll();
						s++;
						for(k=0;k<4;k++) {
							ny = p.y + dy[k];
							nx = p.x + dx[k];
							if(ny<0||ny>n-1||nx<0||nx>m-1) continue;
							if(!visited[ny][nx]) {
								visited[ny][nx] = true;
								if(map[ny][nx]) {
									wall.add(new pos(ny,nx));
								}else {
									q.add(new pos(ny,nx));
								}
							}
						}
					}
					while(!wall.isEmpty()) {
						pos p = wall.poll();
						visited[p.y][p.x] = false;
						ans[p.y][p.x] = (ans[p.y][p.x]+s)%10; 
					}
				}
			}
		}
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) sb.append(ans[i][j]);
			sb.append("\n");
		}
		System.out.println(sb);
	}
	
	
	public static class pos {
		int y,x;
		
		public pos(int y, int x) {
			this.y = y;
			this.x = x;
		}
	}
}
