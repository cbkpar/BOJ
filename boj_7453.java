import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i,j,k,l,r,m;
		long ans;
		n = Integer.parseInt(br.readLine());
		int[][] arr = new int[n][4];
		for(i=0;i<n;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			arr[i][0] = Integer.parseInt(st.nextToken());
			arr[i][1] = Integer.parseInt(st.nextToken());
			arr[i][2] = Integer.parseInt(st.nextToken());
			arr[i][3] = Integer.parseInt(st.nextToken());
		}
		int[] AB = new int[n*n];
		for(i=0;i<n;i++) for(j=0;j<n;j++) AB[i*n+j] = arr[i][0] + arr[j][1];
		Arrays.sort(AB);
		ans = 0;
		for(i=0;i<n;i++) for(j=0;j<n;j++) {
			k = -arr[i][2]-arr[j][3];
			l = 0;
			r = n*n;
			while(l<r) {
				m = (l+r)/2;
				if(AB[m]>k) {
					r = m;
				}else {
					l = m+1;
				}
			}
			ans += l;
			l = 0;
			r = n*n;
			while(l<r) {
				m = (l+r)/2;
				if(AB[m]>=k) {
					r = m;
				}else {
					l = m+1;
				}
			}
			ans -= l;
		}
		System.out.println(ans);
	}
}
