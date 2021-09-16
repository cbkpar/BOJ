import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i,l,r,mx;
		n = Integer.parseInt(br.readLine());
		int[] arr = new int[n+1];
		for(i=1;i<=n;i++) arr[i] = arr[i-1] + Integer.parseInt(br.readLine());
		l = 0;
		r = 1;
		mx = 0;
		while(true) {
			if(l==r||r>n) break;
			mx = Math.max(mx,Math.min(arr[r]-arr[l],arr[n]-arr[r]+arr[l]));
			if(arr[r]-arr[l]>=arr[n]-arr[r]+arr[l]) {
				l++;
			}else {
				r++;
			}
		}
		System.out.println(mx);
	}
}
