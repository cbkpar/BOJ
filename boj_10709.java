import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,m,i,j,k;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int[][] map = new int[n][m];
		for(i=0;i<n;i++) Arrays.fill(map[i],-1);
		for(i=0;i<n;i++) {
			String str = br.readLine();
			for(j=0;j<m;j++) if(str.charAt(j)=='c') map[i][j] = 0;
		}
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				if(map[i][j]==0) {
					for(k=j+1;k<m;k++) {
						if(map[i][k]!=-1) break;
						map[i][k] = k-j;
					}
				}
			}
		}
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				sb.append(map[i][j]+" ");
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}
}
