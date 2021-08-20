import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int t,h,w,i,j,k,num,sz,ny,nx,mx;
		int[] dy = {-1,0,1,0};
		int[] dx = {0,-1,0,1};
		t = Integer.parseInt(br.readLine());
		while(t-->0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			h = Integer.parseInt(st.nextToken());
			w = Integer.parseInt(st.nextToken());
			ArrayList<people> pos = new ArrayList<people>();
			pos.add(new people(0,0));
			int[][] map = new int[h+2][w+2];
			int[][][] cnt = new int[h+2][w+2][3];
			for(i=1;i<=h;i++) {
				String str = br.readLine();
				for(j=1;j<=w;j++) {
					if(str.charAt(j-1)=='#') {
						map[i][j] = 2;
					}else if(str.charAt(j-1)=='*') {
						map[i][j] = 1;
					}else if(str.charAt(j-1)=='$') {
						pos.add(new people(i,j));
					}
				}
			}
			for(i=0;i<=h+1;i++) for(j=0;j<=w+1;j++) Arrays.fill(cnt[i][j],50000000);
			for(i=0;i<3;i++) {
				Queue<people> q = new LinkedList<>();
				boolean[][] visited = new boolean[h+2][w+2];
				visited[pos.get(i).y][pos.get(i).x] = true;
				q.add(pos.get(i));
				num = 0;
				while(!q.isEmpty()) {
					sz = q.size();
					Queue<people> qq = new LinkedList<>();
					while(!q.isEmpty()) qq.add(q.poll());
					for(j=0;j<sz;j++) {
						while(!qq.isEmpty()) {
							people p = qq.poll();
							for(k=0;k<4;k++) {
								ny = p.y + dy[k];
								nx = p.x + dx[k];
								if(ny<0||ny>h+1||nx<0||nx>w+1) continue;
								if(visited[ny][nx]) continue;
								visited[ny][nx] = true;
								if(map[ny][nx]==0) {
									qq.add(new people(ny,nx));
									cnt[ny][nx][i] = num; 
								}else if(map[ny][nx]==2) {
									q.add(new people(ny,nx));
									cnt[ny][nx][i] = num+1; 
								}
							}
						}
					}
					num++;
				}
			}
			mx = Integer.MAX_VALUE;
			for(i=0;i<=h+1;i++) {
				for(j=0;j<=w+1;j++) {
					if(map[i][j]==0) {
						mx = Math.min(mx, cnt[i][j][0]+cnt[i][j][1]+cnt[i][j][2]);
					}else if(map[i][j]==2) {
						mx = Math.min(mx, cnt[i][j][0]+cnt[i][j][1]+cnt[i][j][2]-2);
					}
				}
			}
			sb.append(mx+"\n");
		}
		System.out.println(sb);
	}
}

class people {
	int y,x;
	
	public people(int y, int x) {
		this.y = y;
		this.x = x;
	}
}
