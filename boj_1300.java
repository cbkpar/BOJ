import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i;
		long left,right,mid,ans,t,k;
		n = Integer.parseInt(br.readLine());
		k = Integer.parseInt(br.readLine());
		left = 0;
		right = (long)n*n;
		ans = 0;
		while(left<=right) {
			mid = (left+right)/2;
			t = 0;
			for(i=1;i<=n;i++) t += Math.min(mid/i,n);
			if(t>=k) {
				right = mid-1;
				ans = mid;
			}else {
				left = mid+1;
			}
		}
		System.out.println(ans);
	}
}
