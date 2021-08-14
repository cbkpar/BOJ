import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static int n,m,ans;
	static int[][] map;
	static int[][] dist;
	static boolean[] chk;
	static ArrayList<pos> arr;
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int i,j,k,cnt,sz,ny,nx;
		int[] dy = {-1,0,1,0};
		int[] dx = {0,1,0,-1};
		while(true) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			m = Integer.parseInt(st.nextToken());
			n = Integer.parseInt(st.nextToken());
			if(n==0||m==0) break;
			cnt = 2;
			map = new int[n][m];
			arr = new ArrayList<pos>();
			for(i=0;i<n;i++) {
				String str = br.readLine();
				for(j=0;j<m;j++) {
					if(str.charAt(j)=='o') {
						map[i][j] = 1;
						arr.add(new pos(i,j,1));
					}else if(str.charAt(j)=='*') {
						arr.add(new pos(i,j,cnt));
						map[i][j] = cnt++;
					}else if(str.charAt(j)=='x') {
						map[i][j] = -1;
					}
				}
			}
			if(arr.size()==1) {
				sb.append("0\n");
				continue;
			}
			Collections.sort(arr, new Comparator<pos>() {
				@Override
				public int compare (pos o1, pos o2) {
					return o1.w - o2.w;
				}
			});
			dist = new int[arr.size()][arr.size()];
			for(i=0;i<arr.size();i++) Arrays.fill(dist[i],1000000000);
			for(i=0;i<arr.size();i++) {
				cnt = 1;
				Queue<pos> q = new LinkedList<>();
				q.add(arr.get(i));
				boolean[][] visited = new boolean[n][m];
				visited[arr.get(i).y][arr.get(i).x] = true;
				while(!q.isEmpty()) {
					sz = q.size();
					for(j=0;j<sz;j++) {
						pos p = q.poll();
						for(k=0;k<4;k++) {
							ny = p.y + dy[k];
							nx = p.x + dx[k];
							if(ny<0||ny>n-1||nx<0||nx>m-1) continue;
							if(visited[ny][nx]) continue;
							visited[ny][nx] = true;
							if(map[ny][nx]>=1) {
								dist[i][map[ny][nx]-1] = cnt;
								q.add(new pos(ny,nx,cnt));
							}else if(map[ny][nx]==0) {
								q.add(new pos(ny,nx,cnt));
							}
						}
					}
					cnt++;
				}
			}
			ans = 1000000000;
			chk = new boolean[arr.size()];
			chk[0] = true;
			for(i=1;i<arr.size();i++) {
				if(dist[0][i]==1000000000) continue;
				chk[i] = true;
				dfs(i,1,dist[0][i]);
				chk[i] = false;
			}
			sb.append((ans!=1000000000?ans:"-1")+"\n");
		}
		System.out.println(sb);
	}
	
	public static void dfs(int s, int k, int sum) {
		if(k==arr.size()-1) {
			ans = Math.min(ans, sum);
			return;
		}
		for(int i=1;i<arr.size();i++) {
			if(!chk[i]&&dist[s][i]!=1000000000) {
				chk[i] = true;
				dfs(i,k+1,sum+dist[s][i]);
				chk[i] = false;
			}
		}
	}
	
	public static class pos {
		
		int y,x,w;
		
		public pos(int y, int x, int w) {
			this.y = y;
			this.x = x;
			this.w = w;
		}
	}
}
