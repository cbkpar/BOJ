import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	static int[][] op;
	static int[] arr;
	static int n;
	static boolean chk;
    static StringBuilder sb = new StringBuilder();
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int i,j,k;
		n = Integer.parseInt(br.readLine());
		op = new int[n][n];
		arr = new int[n+1];
		String str = br.readLine();
		k = 0;
		for(i=0;i<n;i++) {
			for(j=i;j<n;j++) {
				if(str.charAt(k)=='-') {
					op[i][j] = -1;
				}else if(str.charAt(k)=='0') {
					op[i][j] = 0;
				}else {
					op[i][j] = 1;
				}
				k++;
			}
		}
		chk = false;
		btr(0);
		System.out.println(sb);
	}
	
	static void btr(int k) {
		if(chk) return;
		if(k==n) {
			for(int i=1;i<=n;i++) sb.append((arr[i]-arr[i-1])+" ");
			chk = true;
			return;
		}
		int mx = 10;
		int mi = -10;
		for(int i=0;i<=k;i++) {
			if(op[i][k]==-1) {
				mx = Math.min(mx, arr[i]-arr[k]-1);
			}else if(op[i][k]==0) {
				mx = Math.min(mx, arr[i]-arr[k]);
				mi = Math.max(mi, arr[i]-arr[k]);
			}else {
				mi = Math.max(mi, arr[i]-arr[k]+1);
			}
		}
		for(int i=mi;i<=mx;i++) {
			arr[k+1] = arr[k] + i;
			btr(k+1);
		}
	}
}
