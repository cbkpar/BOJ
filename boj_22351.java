import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int sz,i,j;
		int[] a = new int[3];
		int[] b = new int[3];
		int[] l = new int[1000];
		for(i=1;i<=999;i++) {
			if(i>=100) {
				l[i] = l[i-1]+3;
			}else if(i>=10) {
				l[i] = l[i-1]+2;
			}else {
				l[i] = l[i-1]+1;
			}
		}
		String str = br.readLine();
		sz = str.length();
		a[0] = str.charAt(0)-'0';
		if(sz>=2) a[1] = a[0]*10+str.charAt(1)-'0';
		if(sz>=3) a[2] = a[1]*10+str.charAt(2)-'0';
		b[0] = str.charAt(sz-1)-'0';
		if(sz>=2) b[1] = (str.charAt(sz-2)-'0')*10+b[0];
		if(sz>=3) b[2] = (str.charAt(sz-3)-'0')*100+b[1];
		for(i=0;i<3;i++) for(j=0;j<3;j++) {
			if(b[j]<a[i]||a[i]==0) continue;
			if(sz==l[b[j]]-l[a[i]-1]) {
				System.out.println(a[i]+" "+b[j]);
				return;
			}
		}
	}
}
