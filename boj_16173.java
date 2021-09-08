import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n,i,j,ny,nx;
        int[] dy = {0,1};
        int[] dx = {1,0};
        n = Integer.parseInt(br.readLine());
        int[][] map = new int[n][n];
        for(i=0;i<n;i++) {
        	StringTokenizer st = new StringTokenizer(br.readLine());
        	for(j=0;j<n;j++) map[i][j] = Integer.parseInt(st.nextToken());
        }
        boolean[][] chk = new boolean[n][n];
        chk[0][0] = true;
        Queue<pos> q = new LinkedList<>();
        q.add(new pos(0,0));
        while(!q.isEmpty()) {
        	pos p = q.poll();
        	for(i=0;i<2;i++) {
        		ny = p.y + dy[i]*map[p.y][p.x];
        		nx = p.x + dx[i]*map[p.y][p.x];
        		if(ny>n-1||nx>n-1) continue;
        		if(chk[ny][nx]) continue;
        		chk[ny][nx] = true;
        		q.add(new pos(ny,nx));
        	}
        }
        System.out.println(chk[n-1][n-1]?"HaruHaru":"Hing");
	}
}

class pos {
	int y,x;
	public pos(int y, int x) {
		this.y = y;
		this.x = x;
	}
}
