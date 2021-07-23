import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i,j,t,s;
		n = Integer.parseInt(br.readLine());
		HashMap<String,Integer> arr = new HashMap<String,Integer>();
		for(i=0;i<n;i++) arr.put(br.readLine(), i);
		boolean[] chk = new boolean[n];
		s = 0;
		for(i=0;i<n;i++) {
			t = arr.get(br.readLine());
			boolean c = true;
			for(j=0;j<t;j++) if(!chk[j]) {
				c = false;
				break;
			}
			if(!c) s++;
			chk[t] = true;
		}
		System.out.println(s);
	}
}
