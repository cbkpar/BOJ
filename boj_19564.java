import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int s,sz,i;
		String str = br.readLine();
		sz = str.length();
		s = 1;
		for(i=1;i<sz;i++) if(str.charAt(i-1)-str.charAt(i)>=0) s++;
		System.out.println(s);
	}
}
