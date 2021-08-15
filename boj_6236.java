import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,m,i,left,right,mid,t,k,ans;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int[] arr = new int[n];
		for(i=0;i<n;i++) arr[i] = Integer.parseInt(br.readLine());
		left = 0;
		ans = right = 1000000001;
		while(left<=right) {
			t = mid = (left+right)/2;
			k = 1;
			for(i=0;i<n;i++) {
				if(t>=arr[i]) {
					t -= arr[i];
				}else {
					t = mid - arr[i];
					if(t<0) {
						k = 99999;
						break;
					}
					k++;
				}
			}
			if(k<=m) {
				ans = Math.min(ans, mid);
				right = mid-1;
			}else {
				left = mid+1;
			}
		}
		System.out.println(ans);
	}
}
