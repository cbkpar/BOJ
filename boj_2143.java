import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t,n,m,i,j;
		long ans;
		t = Integer.parseInt(br.readLine());
		n = Integer.parseInt(br.readLine());
		int[] arr = new int[n+1];
		HashMap<Integer,Integer> cnt = new HashMap<Integer,Integer>();
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(i=1;i<=n;i++) arr[i] = arr[i-1] + Integer.parseInt(st.nextToken());
		for(i=0;i<n;i++) {
			for(j=i+1;j<=n;j++) {
				if(cnt.containsKey(arr[j]-arr[i])) {
					cnt.put(arr[j]-arr[i], cnt.get(arr[j]-arr[i])+1);
				}else {
					cnt.put(arr[j]-arr[i], 1);
				}
			}
		}
		m = Integer.parseInt(br.readLine());
		arr = new int[m+1];
		st = new StringTokenizer(br.readLine());
		for(i=1;i<=m;i++) arr[i] = arr[i-1] + Integer.parseInt(st.nextToken());
		ans = 0;
		for(i=0;i<m;i++) for(j=i+1;j<=m;j++) if(cnt.containsKey(t-arr[j]+arr[i])) ans += (long)cnt.get(t-arr[j]+arr[i]);
		System.out.println(ans);
	}
}
