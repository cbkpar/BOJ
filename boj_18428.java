import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int n;
	static int[][] map;
	static int[] dy = {-1,0,1,0};
	static int[] dx = {0,-1,0,1};
	static boolean flag;
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int i,j;
		n = Integer.parseInt(br.readLine());
		map = new int[n][n];
		for(i=0;i<n;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(j=0;j<n;j++) {
				char c = st.nextToken().charAt(0);
				if(c=='S') {
					map[i][j] = 1;
				}else if(c=='T') {
					map[i][j] = 2;
				}
			}
		}
		flag = false;
		findblank(0,0);
		System.out.println(flag?"YES":"NO");
	}
	
	static void findblank(int k, int cnt) {
		if(cnt==3) {
			brute();
			return;
		}
		for(int i=k;i<n*n;i++) {
			if(map[i/n][i%n]==0) {
				map[i/n][i%n]=3;
				findblank(k+1,cnt+1);
				map[i/n][i%n]=0;
			}
		}
	}
	
	static void brute() {
		int i,j,k,y,x,ty,tx,t;
		for(i=0;i<n;i++) {
			for(j=0;j<n;j++) {
				if(map[i][j]==1) {
					y = i;
					x = j;
					for(k=0;k<4;k++) {
						t = 1;
						ty = y;
						tx = x;
						while(true) {
							ty = y + dy[k]*t;
							tx = x + dx[k]*t;
							if(ty<0||ty>n-1||tx<0||tx>n-1) break;
							if(map[ty][tx]==1||map[ty][tx]==3) break;
							if(map[ty][tx]==2) return;
							t++;
						}
					}
				}
			}
		}
		flag = true;
	}
}
