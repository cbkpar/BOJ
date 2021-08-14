import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,m,i,j,k,a,b,c,d,ny,nx,mx,mi;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int[][] cow = new int[n][2];
		for(i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			cow[i][0] = Integer.parseInt(st.nextToken());
			cow[i][1] = Integer.parseInt(st.nextToken());
		}
		mi = Integer.MAX_VALUE;
		for(i=0;i<n;i++) {
			for(j=0;j<n;j++) {
				ny = cow[i][0]+1;
				nx = cow[j][1]+1;
				a = b = c = d = 0;
				mx = 0;
				for(k=0;k<n;k++) {
					if(cow[k][0]<ny&&cow[k][1]<nx) a++;
					if(cow[k][0]<ny&&cow[k][1]>nx) b++;
					if(cow[k][0]>ny&&cow[k][1]<nx) c++;
					if(cow[k][0]>ny&&cow[k][1]>nx) d++;
				}
				mx = Math.max(mx, a);
				mx = Math.max(mx, b);
				mx = Math.max(mx, c);
				mx = Math.max(mx, d);
				mi = Math.min(mi, mx);
			}
		}
		System.out.println(mi);
	}
}
