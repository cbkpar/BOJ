import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,m,v,i,t;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		v = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int[] arr = new int[n];
		for(i=0;i<n;i++) arr[i] = Integer.parseInt(st.nextToken());
		while(m-->0) {
			t = Integer.parseInt(br.readLine());
			if(t<v) {
				sb.append(arr[t]+"\n");
			}else {
				t -= v-1;
				t %= (n-v+1);
				t += v-1;
				sb.append(arr[t]+"\n");
			}
		}
		System.out.println(sb);
	}
}
