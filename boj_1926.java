import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,m,i,j,cnt,mx,ty,tx,t;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		boolean[][] map = new boolean[n][m];
		for(i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(j=0;j<m;j++) if(Integer.parseInt(st.nextToken())==1) map[i][j] = true;
		}
		cnt = mx = 0;
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				if(map[i][j]) {
					Queue<Integer> qy = new LinkedList<>();
					Queue<Integer> qx = new LinkedList<>();
					cnt++;
					t = 1;
					map[i][j] = false;
					qy.add(i);
					qx.add(j);
					while(!qy.isEmpty()) {
						ty = qy.poll();
						tx = qx.poll();
						if(ty>0) if(map[ty-1][tx]) {
							map[ty-1][tx] = false;
							qy.add(ty-1);
							qx.add(tx);
							t++;
						}
						if(ty<n-1) if(map[ty+1][tx]) {
							map[ty+1][tx] = false;
							qy.add(ty+1);
							qx.add(tx);
							t++;
						}
						if(tx>0) if(map[ty][tx-1]) {
							map[ty][tx-1] = false;
							qy.add(ty);
							qx.add(tx-1);
							t++;
						}
						if(tx<m-1) if(map[ty][tx+1]) {
							map[ty][tx+1] = false;
							qy.add(ty);
							qx.add(tx+1);
							t++;
						}
					}
					mx = Math.max(mx, t);
				}
			}
		}
		System.out.println(cnt+"\n"+mx);
	}
}
