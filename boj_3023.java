import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,m,i,j,p,q;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		boolean[][] chk = new boolean[n*2][m*2];
		for(i=0;i<n;i++) {
			String str = br.readLine();
			for(j=0;j<m;j++) {
				if(str.charAt(j)=='#') {
					chk[i][j] = true;
					chk[i][2*m-j-1] = true;
					chk[2*n-i-1][j] = true;
					chk[2*n-i-1][2*m-j-1] = true;
				}
			}
		}
		st = new StringTokenizer(br.readLine());
		p = Integer.parseInt(st.nextToken())-1;
		q = Integer.parseInt(st.nextToken())-1;
		chk[p][q] = !chk[p][q];
		for(i=0;i<2*n;i++) {
			for(j=0;j<2*m;j++) {
				sb.append(chk[i][j]?"#":".");
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}
}
