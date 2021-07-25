import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int sz,i,s;
		sz = Integer.parseInt(br.readLine());
		String str = br.readLine();
		s = 0;
		for(i=0;i<sz;i++) {
			if(str.charAt(i)=='a') s++;
			if(str.charAt(i)=='e') s++;
			if(str.charAt(i)=='i') s++;
			if(str.charAt(i)=='o') s++;
			if(str.charAt(i)=='u') s++;
		}
		System.out.println(s);
	}
}
