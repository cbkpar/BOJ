import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,m,i,mx,cnt;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int[] arr = new int[n];
		for(i=0;i<n*m;i++) arr[i%n] += Integer.parseInt(st.nextToken());
		mx = -1;
		cnt = 0;
		for(i=n-1;i>=0;i--) {
			if(arr[i]>mx) {
				mx = arr[i];
				cnt = i;
			}
		}
		System.out.println(cnt+1);
	}
}
