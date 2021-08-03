import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static class pos{
		int y,x;
		
		public pos(int y, int x) {
			this.y = y;
			this.x = x;
		}
	}
	
    public static void main(String args[]) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  		StringTokenizer st = new StringTokenizer(br.readLine());
  		int n,m,t,k,sz,y,x,ny,nx,mx;
  		n = Integer.parseInt(st.nextToken());
  		m = Integer.parseInt(st.nextToken());
  		t = Integer.parseInt(st.nextToken());
  		int[] dy = {1,0,-1,0};
  		int[] dx = {0,1,0,-1};
  		boolean[][] visited = new boolean[n][m];
  		int[][] map = new int[n][m];
  		for(int i=0;i<n;i++) {
  			st = new StringTokenizer(br.readLine());
  			for(int j=0;j<m;j++) map[i][j] = Integer.parseInt(st.nextToken());
  		}
        Queue<pos> q = new LinkedList<>();
        q.add(new pos(0,0));
        visited[0][0] = true;
        k = 0;
        mx = Integer.MAX_VALUE;
        while(true) {
        	if(q.isEmpty()) break;
        	if(k>t) break;
        	if(visited[n-1][m-1]) {
        		System.out.println(Math.min(k,mx));
        		return;
        	}
        	sz = q.size();
        	for(int i=0;i<sz;i++) {
        		pos p = q.poll();
        		y = p.y;
        		x = p.x;
        		if(map[y][x]==2) if(k-2+n-y+m-x<=t) mx = k-2+n-y+m-x;
        		for(int j=0;j<4;j++) {
        			ny = y + dy[j];
        			nx = x + dx[j];
        			if(ny<0||ny>n-1||nx<0||nx>m-1) continue;
        			if(map[ny][nx]==1) continue;
        			if(visited[ny][nx]) continue;
        			visited[ny][nx] = true;
        			q.add(new pos(ny,nx));
        		}
        	}
        	k++;
        }
        System.out.println(mx!=Integer.MAX_VALUE?mx:"Fail");
    }
}
