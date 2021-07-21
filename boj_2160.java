import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i,j,p,q,t,m,a,b;
		n = Integer.parseInt(br.readLine());
		String[][] map = new String[n][5];
		for(i=0;i<n;i++) for(j=0;j<5;j++) map[i][j] = br.readLine();
		m = a = 0;
		b = 1;
		for(i=0;i<n-1;i++) {
			for(j=i+1;j<n;j++) {
				t = 0;
				for(p=0;p<5;p++) {
					for(q=0;q<7;q++) {
						if(map[i][p].charAt(q)==map[j][p].charAt(q)) t++;
					}
				}
				if(t>m) {
					m = t;
					a = i;
					b = j;
				}
			}
		}
		System.out.println((a+1)+" "+(b+1));
	}
}
