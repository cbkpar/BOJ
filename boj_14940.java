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
		int n,m,i,j,t,sz,ny,nx;
		int[] dy = {1,0,-1,0};
		int[] dx = {0,1,0,-1};
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int[][] map = new int[n][m];
		Queue<pos> q = new LinkedList<>();
		for(i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(j=0;j<m;j++) {
				t = Integer.parseInt(st.nextToken());
				if(t==1) {
					map[i][j] = -1;
				}else if(t==2) {
					q.add(new pos(i,j));
				}
			}
		}
		t = 0;
		while(!q.isEmpty()) {
			t++;
			sz = q.size();
			for(i=0;i<sz;i++) {
				pos p = q.poll();
				for(j=0;j<4;j++) {
					ny = p.y + dy[j];
					nx = p.x + dx[j];
					if(ny<0||ny>n-1||nx<0||nx>m-1) continue;
					if(map[ny][nx]!=-1) continue;
					map[ny][nx] = t;
					q.add(new pos(ny,nx));
				}
			}
		}
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				sb.append(map[i][j]+" ");
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}
	
	static class pos {
		int y,x;
		
		public pos(int y, int x) {
			this.y = y;
			this.x = x;
		}
	}
}
