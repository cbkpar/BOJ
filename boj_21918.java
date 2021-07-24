import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,m,i,t,l,r;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int[] arr = new int[n];
		st = new StringTokenizer(br.readLine());
		for(i=0;i<n;i++) arr[i] = Integer.parseInt(st.nextToken());
		while(m-->0) {
			st = new StringTokenizer(br.readLine());
			t = Integer.parseInt(st.nextToken());
			l = Integer.parseInt(st.nextToken());
			r = Integer.parseInt(st.nextToken());
			if(t==1) {
				arr[l-1] = r;
			}else if(t==2) {
				for(i=l-1;i<r;i++) arr[i] = (arr[i]+1)%2;
			}else if(t==3) {
				for(i=l-1;i<r;i++) arr[i] = 0;
			}else {
				for(i=l-1;i<r;i++) arr[i] = 1;
			}
		}
		for(i=0;i<n;i++) sb.append(arr[i]+" ");
		System.out.println(sb);
	}
}
