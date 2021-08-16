import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int[][] ts;
	static int[][] score;
	static int[] teama = {0,0,0,0,0,1,1,1,1,2,2,2,3,3,4};
	static int[] teamb = {1,2,3,4,5,2,3,4,5,3,4,5,4,5,5};
	static boolean chk;
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int t,i,j;
		t = 4;
		while(t-->0) {
			score = new int[6][3];
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(i=0;i<6;i++) for(j=0;j<3;j++) score[i][j] = Integer.parseInt(st.nextToken());
			chk = false;
			ts = new int[6][3];
			dfs(0);
			sb.append(chk?"1 ":"0 ");
		}
		System.out.println(sb);
	}
	
	public static void dfs(int k) {
		if(chk) return;
		if(k==15) {
			for(int i=0;i<6;i++) for(int j=0;j<3;j++) if(ts[i][j]!=score[i][j]) return;
			chk = true;
			return;
		}
		for(int i=0;i<3;i++) {
			if(i==0) {
				ts[teama[k]][0]++;
				ts[teamb[k]][2]++;
				dfs(k+1);
				ts[teama[k]][0]--;
				ts[teamb[k]][2]--;
			}else if(i==1) {
				ts[teama[k]][1]++;
				ts[teamb[k]][1]++;
				dfs(k+1);
				ts[teama[k]][1]--;
				ts[teamb[k]][1]--;
			}else {
				ts[teama[k]][2]++;
				ts[teamb[k]][0]++;
				dfs(k+1);
				ts[teama[k]][2]--;
				ts[teamb[k]][0]--;
			}
		}
	}
}
