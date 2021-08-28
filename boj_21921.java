import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,x,i,mx,cnt,t;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		x = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int[] presum = new int[n+1];
		for(i=1;i<=n;i++) presum[i] = presum[i-1] + Integer.parseInt(st.nextToken());
		cnt = mx = 0;
		for(i=0;i<=n-x;i++) {
			t = presum[i+x]-presum[i];
			if(t>mx) {
				mx = Math.max(mx, presum[i+x]-presum[i]);
				cnt = 1;
			}else if(t==mx) {
				cnt++;
			}
		}
		if(mx==0) {
			System.out.println("SAD");
		}else {
			System.out.println(mx+"\n"+cnt);
		}
	}
}
