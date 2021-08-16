import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i,s,e,ans,mx,t;
		int[] arr = new int[367];
		n = Integer.parseInt(br.readLine());
		while(n-->0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			s = Integer.parseInt(st.nextToken());
			e = Integer.parseInt(st.nextToken());
			for(i=s;i<=e;i++) arr[i]++;
		}
		ans = mx = t = 0;
		for(i=1;i<=366;i++) {
			if(arr[i]!=0) {
				mx = Math.max(mx, arr[i]);
				t++;
			}else {
				ans += mx * t;
				mx = t = 0;
			}
		}
		System.out.println(ans);
	}
}
