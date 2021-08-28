import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int sz,i,j,t;
		while(true) {
			String str = br.readLine();
			if(str.equals("*")) break;
			sz = str.length();
			boolean chk = true;
			t = 1;
			for(i=sz-2;i>=0;i--) {
				if(!chk) break;
				HashSet<String> set = new HashSet<String>();
				for(j=0;j<=i;j++) {
					String tmp = ""+str.charAt(j)+str.charAt(j+t);
					if(set.contains(tmp)) {
						chk = false;
						break;
					}else {
						set.add(tmp);
					}
				}
				t++;
			}
			sb.append(str+" is "+(chk?"":"NOT ")+"surprising.\n");
		}
		System.out.println(sb);
	}
}
