import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int sz,i;
		String str = br.readLine();
		sz = str.length();
		for(i=0;i<sz;i++) {
			if(str.charAt(i)=='I') continue;
			if(str.charAt(i)=='O') continue;
			if(str.charAt(i)=='S') continue;
			if(str.charAt(i)=='H') continue;
			if(str.charAt(i)=='Z') continue;
			if(str.charAt(i)=='X') continue;
			if(str.charAt(i)=='N') continue;
			System.out.println("NO");
			return;
		}
		System.out.println("YES");
	}
}
