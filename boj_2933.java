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
		int r,c,i,j,k,n,t,h;
		StringTokenizer st = new StringTokenizer(br.readLine());
		r = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		boolean[][] map = new boolean[r][c];
		for(i=0;i<r;i++) {
			String str = br.readLine();
			for(j=0;j<c;j++) if(str.charAt(j)=='x') map[i][j] = true;
		}
		n = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		boolean isleft = true;
		while(n-->0) {
			t = r - Integer.parseInt(st.nextToken());
			if(isleft) {
				for(i=0;i<c;i++) {
					if(map[t][i]) {
						map[t][i] = false;
						break;
					}
				}
			}else {
				for(i=c-1;i>=0;i--) {
					if(map[t][i]) {
						map[t][i] = false;
						break;
					}
				}
			}
			isleft = !isleft;
			boolean[][] visited = new boolean[r][c];
			Queue<pos> q = new LinkedList<>();
			for(i=0;i<c;i++) {
				if(map[r-1][i]) {
					visited[r-1][i] = true;
					q.add(new pos(r-1,i));
				}
			}
			while(!q.isEmpty()) {
				pos p = q.poll();
				if(p.r>0) if(map[p.r-1][p.c]&&!visited[p.r-1][p.c]) {
					visited[p.r-1][p.c] = true;
					q.add(new pos(p.r-1,p.c));
				}
				if(p.r<r-1) if(map[p.r+1][p.c]&&!visited[p.r+1][p.c]) {
					visited[p.r+1][p.c] = true;
					q.add(new pos(p.r+1,p.c));
				}
				if(p.c>0) if(map[p.r][p.c-1]&&!visited[p.r][p.c-1]) {
					visited[p.r][p.c-1] = true;
					q.add(new pos(p.r,p.c-1));
				}
				if(p.c<c-1) if(map[p.r][p.c+1]&&!visited[p.r][p.c+1]) {
					visited[p.r][p.c+1] = true;
					q.add(new pos(p.r,p.c+1));
				}
			}
			h = Integer.MAX_VALUE;
			for(i=r-1;i>=0;i--) {
				for(j=0;j<c;j++) {
					if(map[i][j]&&!visited[i][j]) {
						for(k=i+1;k<r;k++) {
							if(map[k][j]) {
								if(!visited[k][j]) continue;
								break;
							}
						}
						h = Math.min(h, k-i-1);
					}
				}
			}
			for(i=r-1;i>=0;i--) {
				for(j=0;j<c;j++) {
					if(map[i][j]&&!visited[i][j]) {
						map[i][j] = false;
						map[i+h][j] = true;
					}
				}
			}
		}
		for(i=0;i<r;i++) {
			for(j=0;j<c;j++) sb.append(map[i][j]?"x":".");
			sb.append("\n");
		}
		System.out.println(sb);
	}
	
	public static class pos {
		int r;
		int c;
		
		public pos(int r, int c) {
			this.r = r;
			this.c = c;
		}
	}
}
