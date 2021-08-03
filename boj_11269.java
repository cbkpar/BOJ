import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int sz,i,s;
		char[] arr = br.readLine().toCharArray();
		sz = arr.length;
		s = 0;
		for(i=0;i<sz;i+=3) {
			if(arr[i]!='P') s++;
			if(arr[i+1]!='E') s++;
			if(arr[i+2]!='R') s++;
		}
		System.out.println(s);
	}
}
