import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,k,i,j,sz,ny,nx,s,y,x;
		int[] dy = {1,0,-1,0};
		int[] dx = {0,1,0,-1};
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		int[][] map = new int[n][n];
        ArrayList<virus> arr = new ArrayList<>();
		for(i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(j=0;j<n;j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if(map[i][j]!=0) arr.add(new virus(i, j, map[i][j]));
			}
		}
		st = new StringTokenizer(br.readLine());
		s = Integer.parseInt(st.nextToken());
		y = Integer.parseInt(st.nextToken())-1;
		x = Integer.parseInt(st.nextToken())-1;
		Collections.sort(arr, new Comparator<virus>() {
			@Override
			public int compare(virus o1, virus o2) {
				return o1.num-o2.num;
			}
		});
		Queue<virus> q = new LinkedList<>();
		for(virus v:arr) q.add(v);
		while(!q.isEmpty()) {
			if(s==0) break;
			sz = q.size();
			for(i=0;i<sz;i++) {
				for(j=0;j<4;j++) {
					ny = q.peek().y+dy[j];
					nx = q.peek().x+dx[j];
					if(ny<0||ny>n-1||nx<0||nx>n-1) continue;
					if(map[ny][nx]!=0) continue;
					map[ny][nx] = q.peek().num;
					q.add(new virus(ny,nx,q.peek().num));
				}
				q.poll();
			}
			s--;
		}
		System.out.println(map[y][x]);
	}
	
	public static class virus {
		int y;
		int x;
		int num;
		
		public virus(int y, int x, int num) {
			this.y = y;
			this.x = x;
			this.num = num;
		}
	}
}
