import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i,mx,cnt;
		n = Integer.parseInt(br.readLine());
		int[] arr = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(i=0;i<n;i++) arr[i] = Integer.parseInt(st.nextToken());
		mx = 1;
		cnt = 1;
		for(i=1;i<n;i++) {
			if(arr[i]>=arr[i-1]) {
				mx = Math.max(mx, ++cnt);
			}else {
				cnt = 1;
			}
		}
		cnt = 1;
		for(i=1;i<n;i++) {
			if(arr[i]<=arr[i-1]) {
				mx = Math.max(mx, ++cnt);
			}else {
				cnt = 1;
			}
		}
		System.out.println(mx);
	}
}
