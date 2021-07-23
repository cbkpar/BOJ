import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,m,i,j,s;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		s = n*m;
		boolean[][] map = new boolean[n][m];
		for(i=0;i<n;i++) {
			String str = br.readLine();
			for(j=0;j<m;j++) if(str.charAt(j)=='-') map[i][j] = true;
		}
		for(i=0;i<n;i++) for(j=0;j<m-1;j++) if(map[i][j]&&map[i][j+1]) s--;
		for(i=0;i<m;i++) for(j=0;j<n-1;j++) if(!map[j][i]&&!map[j+1][i]) s--;
		System.out.println(s);
	}
}
