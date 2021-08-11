import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	
	static int n;
	static int[][] map;
	static int[][] cost;
	static int[] dy = {1,0,-1,0};
	static int[] dx = {0,1,0,-1};
	static PriorityQueue<pos> pq = new PriorityQueue<pos>();
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int t,i,j;
		t = 0;
		while(true) {
			n = Integer.parseInt(br.readLine());
			if(n==0) break;
			t++;
			map = new int[n][n];
			cost = new int[n][n];
			for(i=0;i<n;i++) Arrays.fill(cost[i], Integer.MAX_VALUE);
			for(i=0;i<n;i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				for(j=0;j<n;j++) map[i][j] = Integer.parseInt(st.nextToken());
			}
			sb.append("Problem "+t+": "+dijkstra()+"\n");
		}
		System.out.println(sb);
	}
	
	public static int dijkstra() {
		cost[0][0] = map[0][0];
		pq.add(new pos(0,0,map[0][0]));
		while(!pq.isEmpty()) {
			pos p = pq.poll();
			for(int i=0;i<4;i++) {
				int ny = p.y + dy[i];
				int nx = p.x + dx[i];
				if(ny<0||ny>n-1||nx<0||nx>n-1) continue;
				if(cost[ny][nx]>cost[p.y][p.x]+map[ny][nx]) {
					cost[ny][nx] = cost[p.y][p.x]+map[ny][nx];
					pq.add(new pos(ny,nx,cost[ny][nx]));
				}
			}
		}
	return cost[n-1][n-1];
	}
	
	public static class pos implements Comparable<pos> {
		int y;
		int x;
		int c;
		
		public pos(int y, int x, int c) {
			this.y = y;
			this.x = x;
			this.c = c;
		}
		
		@Override
		public int compareTo(pos o) {
			return this.c - o.c;
		}
	}
}
