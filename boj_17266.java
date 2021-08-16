import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int l,n,i,left,right,mid,ans;
		l = Integer.parseInt(br.readLine());
		n = Integer.parseInt(br.readLine());
		int[] arr = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(i=0;i<n;i++) arr[i] = Integer.parseInt(st.nextToken());
		left = Math.max(arr[0], l-arr[n-1]);
		ans = right = l;
		while(left<=right) {
			mid = (left+right)/2;
			boolean chk = true;
			for(i=0;i<n-1;i++) {
				if(arr[i]+mid<arr[i+1]-mid) {
					chk = false;
					break;
				}
			}
			if(chk) {
				ans = Math.min(ans, mid);
				right = mid-1;
			}else {
				left = mid+1;
			}
		}
		System.out.println(ans);
	}
}
