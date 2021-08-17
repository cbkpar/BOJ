import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,m,i,t;
		char c;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		String a = br.readLine();
		String b = br.readLine();
		char[] arr = new char[n+m];
		int[] d = new int[n+m];
		for(i=n-1;i>=0;i--) {
			arr[i] = a.charAt(n-i-1);
			d[i] = 1;
		}
		for(i=0;i<m;i++) {
			arr[n+i] = b.charAt(i);
			d[n+i] = 2;
		}
		t = Integer.parseInt(br.readLine());
		while(t-->0) {
			for(i=0;i<n+m-1;i++) {
				if(d[i]==1&&d[i+1]==2) {
					d[i] = 2;
					d[i+1] = 1;
					c = arr[i];
					arr[i] = arr[i+1];
					arr[i+1] = c;
					i++;
				}
			}
		}
		System.out.println(arr);
	}
}
