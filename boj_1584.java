import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	int n,t,i,j,a,b,c,d,h,sz,nx,ny;
    	int[][] map = new int[501][501];
    	int[][] danger = new int[503][503];
    	int[] dy = {-1,0,1,0};
    	int[] dx = {0,-1,0,1};
    	n = Integer.parseInt(br.readLine());
    	while(n-->0) {
    		StringTokenizer st = new StringTokenizer(br.readLine());
    		a = Integer.parseInt(st.nextToken())+1;
    		b = Integer.parseInt(st.nextToken())+1;
    		c = Integer.parseInt(st.nextToken())+1;
    		d = Integer.parseInt(st.nextToken())+1;
    		if(a>c) {
    			t = a;
    			a = c;
    			c = t;
    		}
    		if(b>d) {
    			t = b;
    			b = d;
    			d = t;
    		}
    		danger[a][b]++;
    		danger[a][d+1]--;
    		danger[c+1][b]--;
    		danger[c+1][d+1]++;
    	}
    	for(i=1;i<=501;i++) {
    		for(j=1;j<=501;j++) {
    			danger[i][j] += danger[i-1][j] + danger[i][j-1] - danger[i-1][j-1];
    		}
    	}
    	for(i=1;i<=501;i++) for(j=1;j<=501;j++) if(danger[i][j]>0) map[i-1][j-1] = 1;
    	danger = new int[503][503];
    	n = Integer.parseInt(br.readLine());
    	while(n-->0) {
    		StringTokenizer st = new StringTokenizer(br.readLine());
    		a = Integer.parseInt(st.nextToken())+1;
    		b = Integer.parseInt(st.nextToken())+1;
    		c = Integer.parseInt(st.nextToken())+1;
    		d = Integer.parseInt(st.nextToken())+1;
    		if(a>c) {
    			t = a;
    			a = c;
    			c = t;
    		}
    		if(b>d) {
    			t = b;
    			b = d;
    			d = t;
    		}
    		danger[a][b]++;
    		danger[a][d+1]--;
    		danger[c+1][b]--;
    		danger[c+1][d+1]++;
    	}
    	for(i=1;i<=501;i++) {
    		for(j=1;j<=501;j++) {
    			danger[i][j] += danger[i-1][j] + danger[i][j-1] - danger[i-1][j-1];
    		}
    	}
    	for(i=1;i<=501;i++) for(j=1;j<=501;j++) if(danger[i][j]>0) map[i-1][j-1] = -1;
    	boolean[][] chk = new boolean[501][501];
    	h = 0;
        Queue<pos> q = new LinkedList<>();
        Queue<pos> tq = new LinkedList<>();
        q.add(new pos(0,0));
        while(!q.isEmpty()) {
        	sz = q.size();
        	for(i=0;i<sz;i++) {
        		tq.add(q.poll());
        		while(!tq.isEmpty()) {
        			pos p = tq.poll();
        			if(p.x==500&&p.y==500) {
        				System.out.println(h);
        				return;
        			}
        			for(j=0;j<4;j++) {
        				nx = p.x + dx[j];
        				ny = p.y + dy[j];
        				if(nx<0||nx>500||ny<0||ny>500) continue;
        				if(chk[nx][ny]) continue;
        				chk[nx][ny] = true;
        				if(map[nx][ny]==-1) continue;
        				if(map[nx][ny]==0) tq.add(new pos(nx,ny));
        				if(map[nx][ny]==1) q.add(new pos(nx,ny));
        			}
        		}
        	}
        	h++;
        }
    	System.out.println("-1");
    }
}

class pos {
	int x,y;
	public pos(int x, int y) {
		this.x = x;
		this.y = y;
	}
}
