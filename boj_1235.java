import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,s,sz,i;
		String str;
		n = Integer.parseInt(br.readLine());
		String[] arr = new String[n];
		for(i=0;i<n;i++) arr[i] = br.readLine();
		s = 1;
		sz = arr[0].length();
		while(true) {
			HashSet<String> set = new HashSet<String>();
			boolean chk = true;
			for(i=0;i<n;i++) {
				str = arr[i].substring(sz-s);
				if(set.contains(str)) {
					chk = false;
					break;
				}else {
					set.add(str);
				}
			}
			if(chk) {
				System.out.println(s);
				return;
			}else {
				s++;
			}
		}
	}
}
