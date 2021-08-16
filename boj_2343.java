import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,m,cnt,i;
		long left,right,mid,t,ans;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int[] arr = new int[n];
		st = new StringTokenizer(br.readLine());
		for(i=0;i<n;i++) arr[i] = Integer.parseInt(st.nextToken());
		left = 0;
		ans = right = 10000000001L;
		while(left<=right) {
			t = mid = (left+right)/2;
			cnt = 1;
			for(i=0;i<n;i++) {
				if(t>=arr[i]) {
					t -= arr[i];
				}else {
					t = mid - arr[i];
					cnt++;
					if(t<0) {
						cnt = 9999999;
						break;
					}
				}
			}
			if(cnt<=m) {
				ans = Math.min(ans, mid);
				right = mid-1;
			}else {
				left = mid+1;
			}
		}
		System.out.println(ans);
	}
}
