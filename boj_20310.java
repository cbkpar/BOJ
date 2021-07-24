import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int sz,i,a,b;
		String str = br.readLine();
		sz = str.length();
		a = b = 0;
		for(i=0;i<sz;i++) if(str.charAt(i)=='0') {
			a++;
		}else {
			b++;
		}
		a/=2;
		b/=2;
		for(i=0;i<sz;i++) if(str.charAt(i)=='0') {
			if(a>0) sb.append("0");
			a--;
		}else {
			if(b<=0) sb.append("1");
			b--;
		}
		System.out.println(sb);
	}
}
