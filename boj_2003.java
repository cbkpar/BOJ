import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,m,i,s,l,r,t;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int[] arr = new int[n+1];
		st = new StringTokenizer(br.readLine());
		for(i=1;i<=n;i++) arr[i] = arr[i-1] + Integer.parseInt(st.nextToken());
		s = 0;
		l = 0;
		r = 1;
		while(true) {
			if(r>n) break;
			t = arr[r] - arr[l];
			if(t>=m) l++;
			if(t<=m) r++;
			if(t==m) s++;
		}
		System.out.println(s);
	}
}
