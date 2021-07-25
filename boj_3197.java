import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int r,c,i,j,tr,tc,d,sz,nr,nc;
		int[] dr = {0,-1,0,1};
		int[] dc = {1,0,-1,0};
		StringTokenizer st = new StringTokenizer(br.readLine());
		r = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		int[][] map = new int[r][c];
		boolean[][] visited = new boolean[r][c];
		Queue<pos> water = new LinkedList<>();
		Queue<pos> bird = new LinkedList<>();
		Queue<pos> birdt = new LinkedList<>();
		tr = tc = 0;
		for(i=0;i<r;i++) {
			String str = br.readLine();
			for(j=0;j<c;j++) {
				if(str.charAt(j)=='.') {
					map[i][j] = 1;
					water.add(new pos(i,j));
				}else if(str.charAt(j)=='L') {
					map[i][j] = 2;
					tr = i;
					tc = j;
					water.add(new pos(i,j));
				}
			}
		}
		bird.add(new pos(tr,tc));
		visited[tr][tc] = true;
		d = 0;
		while(true) {
			sz = bird.size();
			for(i=0;i<sz;i++) {
				birdt.add(bird.poll());
				while(!birdt.isEmpty()) {
					tr = birdt.peek().r;
					tc = birdt.poll().c;
					for(j=0;j<4;j++) {
						nr = tr + dr[j];
						nc = tc + dc[j];
						if(nr<0||nr>=r||nc<0||nc>=c) continue;
						if(visited[nr][nc]) continue;
						visited[nr][nc] = true;
						if(map[nr][nc]==0) {
							bird.add(new pos(nr,nc));
						}else if(map[nr][nc]==1) {
							birdt.add(new pos(nr,nc));
						}else {
							System.out.println(d);
							return;
						}
					}
				}
			}
			sz = water.size();
			for(i=0;i<sz;i++) {
				tr = water.peek().r;
				tc = water.poll().c;
				for(j=0;j<4;j++) {
					nr = tr + dr[j];
					nc = tc + dc[j];
					if(nr<0||nr>=r||nc<0||nc>=c) continue;
					if(map[nr][nc]==0) {
						map[nr][nc]=1;
						water.add(new pos(nr,nc));
					}
				}
			}
			d++;
		}
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
