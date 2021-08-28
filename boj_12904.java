import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int asz,bsz,l,r,i;
		boolean chk = false;
		String a,b;
		a = br.readLine();
		b = br.readLine();
		asz = a.length();
		bsz = b.length();
		l = 0;
		r = bsz-1;
		while(bsz>asz) {
			if(!chk) {
				if(b.charAt(r)=='B') chk = !chk;
				r--;
			}else {
				if(b.charAt(l)=='B') chk = !chk;
				l++;
			}
			bsz--;
		}
		if(!chk) {
			for(i=0;i<=r-l;i++) {
				if(a.charAt(i)!=b.charAt(l+i)) {
					System.out.println("0");
					return;
				}
			}
		}else {
			for(i=0;i<=r-l;i++) {
				if(a.charAt(i)!=b.charAt(r-i)) {
					System.out.println("0");
					return;
				}
			}
		}
		System.out.println("1");
	}
}
