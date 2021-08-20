import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int i,sz,r,p,mx;
		String str = br.readLine();
		sz = str.length();
		char[] c = new char[sz*2+1];
		int[] l = new int[sz*2+1];
		Arrays.fill(c,'#');
		for(i=0;i<sz;i++) c[i*2+1] = str.charAt(i);
		r = p = 0;
		for(i=0;i<sz*2+1;i++) {
			if(i<=r) {
				l[i] = Math.min(l[2*p-i], r-i);
			}else {
				l[i] = 0;
			}
			while(i-l[i]-1>=0&&i+l[i]+1<sz*2+1&&c[i-l[i]-1]==c[i+l[i]+1]) l[i]++;
			if(r<i+l[i]) {
				r = i+l[i];
				p = i;
			}
		}
		mx = 0;
		for(i=0;i<sz*2+1;i++) mx = Math.max(mx, l[i]);
		System.out.println(mx);
	}
}
