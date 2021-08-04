import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,s,sz,i;
		n = Integer.parseInt(br.readLine());
		s = 0;
		while(n-->0) {
			String str = br.readLine();
			sz = str.length();
			for(i=1;i<sz;i++) if(str.charAt(i-1)=='C'&&str.charAt(i)=='D') break;
			if(i==sz) s++;
		}
		System.out.println(s);
	}
}
