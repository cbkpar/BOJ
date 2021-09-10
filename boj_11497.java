import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int t,n,i,s;
		t = Integer.parseInt(br.readLine());
		while(t-->0) {
			n = Integer.parseInt(br.readLine());
			int[] arr = new int[n];
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(i=0;i<n;i++) arr[i] = Integer.parseInt(st.nextToken());
			Arrays.sort(arr);
			s = arr[1]-arr[0];
			for(i=2;i<n;i++) s = Math.max(s, arr[i]-arr[i-2]);
			sb.append(s+"\n");
		}
		System.out.println(sb);
	}
}
