import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,m,i,j,p,l,s;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int[] arr = new int[n];
		for(i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			p = Integer.parseInt(st.nextToken());
			l = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			if(p>=l) {
				int[] sub = new int[p];
				for(j=0;j<p;j++) sub[j] = Integer.parseInt(st.nextToken());
				Arrays.sort(sub);
				arr[i] = sub[p-l];
			}else {
				arr[i] = 1;
			}
		}
		Arrays.sort(arr);
		s = 0;
		for(i=0;i<n;i++) {
			if(arr[i]>m) break;
			m -= arr[i];
			s++;
		}
		System.out.println(s);
	}
}
