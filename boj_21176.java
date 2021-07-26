import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int k,r,i,mx,m,t;
		StringTokenizer st = new StringTokenizer(br.readLine());
		k = Integer.parseInt(st.nextToken());
		r = Integer.parseInt(st.nextToken());
		int[] arr = new int[k];
		st = new StringTokenizer(br.readLine());
		for(i=0;i<k;i++) arr[i] = Integer.parseInt(st.nextToken());
		mx = 0;
		while(r-->0) {
			m = Integer.MAX_VALUE;
			st = new StringTokenizer(br.readLine());
			for(i=0;i<k;i++) {
				t = Integer.parseInt(st.nextToken());
				if(t==0) continue;
				m = Math.min(m, arr[i]/t);
			}
			mx = Math.max(mx, m*Integer.parseInt(st.nextToken()));
		}
		System.out.println(mx);
	}
}
