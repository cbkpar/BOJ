import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,m,i,t,s;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int[][] arr = new int[n][2];
		int[] chk = new int[n];
		for(i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			arr[i][0] = Integer.parseInt(st.nextToken());
			arr[i][1] = Integer.parseInt(st.nextToken());
		}
		while(m-->0) {
			t = Integer.parseInt(br.readLine());
			for(i=0;i<n;i++) if(arr[i][chk[i]]<=t) chk[i] = (chk[i]+1)%2;
		}
		s = 0;
		for(i=0;i<n;i++) for(i=0;i<n;i++) s += arr[i][chk[i]];
		System.out.println(s);
	}
}
