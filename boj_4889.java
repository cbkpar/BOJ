import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int sz,i,p,q,t;
		t = 0;
		while(true) {
			String str = br.readLine();
			if(str.charAt(0)=='-') break;
			t++;
			sz = str.length();
			p = q = 0;
			for(i=0;i<sz;i++) {
				if(str.charAt(i)=='{') {
					p++;
				}else {
					if(p>0) {
						p--;
					}else {
						q++;
					}
				}
			}
			sb.append(t+". "+((p+1)/2+(q+1)/2)+"\n");
		}
		System.out.println(sb);
	}
}
