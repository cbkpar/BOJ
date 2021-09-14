import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n,m,i,s,e,h;
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int[] arr = new int[n+2];
		int[] tarr = new int[n+2];
		st = new StringTokenizer(br.readLine());
		for(i=1;i<=n;i++) arr[i] = Integer.parseInt(st.nextToken());
		while(m-->0) {
			st = new StringTokenizer(br.readLine());
			s = Integer.parseInt(st.nextToken());
			e = Integer.parseInt(st.nextToken());
			h = Integer.parseInt(st.nextToken());
			tarr[s] += h;
			tarr[e+1] -= h;
		}
		for(i=1;i<=n;i++) tarr[i] += tarr[i-1];
		for(i=1;i<=n;i++) arr[i] += tarr[i];
		for(i=1;i<=n;i++) sb.append(arr[i]+" ");
		System.out.println(sb);
	}
}
