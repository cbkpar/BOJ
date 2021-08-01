import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i,l,r,m,t,tl,tr;
		n = Integer.parseInt(br.readLine());
		int[] arr = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(i=0;i<n;i++) arr[i] = Integer.parseInt(st.nextToken());
		Arrays.sort(arr);
		tl =l = 0;
		tr = r = n-1;
		m = Integer.MAX_VALUE;
		while(l<r) {
			t = arr[r]+arr[l];
			if(Math.abs(t)<m) {
				m = Math.abs(t);
				tl = l;
				tr = r;
			}
			if(t==0) break;
			if(t>0) r--;
			if(t<0) l++;
		}
		System.out.println(arr[tl]+" "+arr[tr]);
	}
}
