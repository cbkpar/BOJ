import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,t,s,sz,i;
		t = s = 0;
		n = Integer.parseInt(br.readLine());
		while(n-->0) {
			String str = br.readLine();
			sz = str.length();
			for(i=0;i<sz;i++) {
				if(str.charAt(i)=='s'||str.charAt(i)=='S') s++;
				if(str.charAt(i)=='t'||str.charAt(i)=='T') t++;
			}
		}
		if(t>s) {
			System.out.println("English");
		}else {
			System.out.println("French");
		}
	}
}
