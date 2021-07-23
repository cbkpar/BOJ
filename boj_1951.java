import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,sz,ans,i;
		String str = br.readLine();
		sz = str.length();
		n = Integer.parseInt(str);
		ans = 0;
		for(i=1;i<sz;i++) ans = (ans+9*i*((int)Math.pow(10, i-1)%1234567))%1234567;
		ans = (ans+sz*((n+1-(int)Math.pow(10, sz-1))%1234567))%1234567;
		System.out.println(ans);
	}
}
