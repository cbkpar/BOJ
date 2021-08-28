import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,m,i,j;
		String a,b;
		int[] trans = {3,2,1,2,4,3,1,3,1,1,3,1,3,2,1,2,2,2,1,2,1,1,1,2,2,1};
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		a = st.nextToken(); 
		b = st.nextToken();
		int[] arr = new int[n+m];
		if(n>m) {
			for(i=0;i<m;i++) {
				arr[i*2] = trans[a.charAt(i)-'A'];
				arr[i*2+1] = trans[b.charAt(i)-'A'];
			}
			for(i=m;i<n;i++) arr[m+i] = trans[a.charAt(i)-'A'];
		}else {
			for(i=0;i<n;i++) {
				arr[i*2] = trans[a.charAt(i)-'A'];
				arr[i*2+1] = trans[b.charAt(i)-'A'];
			}
			for(i=n;i<m;i++) arr[n+i] = trans[b.charAt(i)-'A'];
		}
		for(i=n+m-2;i>0;i--) {
			for(j=0;j<=i;j++) {
				arr[j] = (arr[j]+arr[j+1])%10;
			}
		}
		System.out.println((arr[0]*10+arr[1])+"%");
	}
}
