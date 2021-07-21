import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,m,i,j,k,p,q,s;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		boolean[][] chk = new boolean[n+1][n+1];
		while(m-->0) {
			st = new StringTokenizer(br.readLine());
			p = Integer.parseInt(st.nextToken());
			q = Integer.parseInt(st.nextToken());
			chk[p][q] = chk[q][p] = true;
		}
		s = 0;
		for(i=1;i<=n;i++) {
			for(j=i+1;j<=n;j++) {
				for(k=j+1;k<=n;k++) {
					if(chk[i][j]||chk[j][k]||chk[k][i]) continue;
					s++;
				}
			}
		}
		System.out.println(s);
	}
}
