import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,k,sz,left,right,tl,tr;
		boolean chk;
		n = Integer.parseInt(br.readLine());
		while(n-->0) {
			String str = br.readLine();
			sz = str.length();
			left = 0;
			right = sz-1;
			k = 0;
			while(left<right) {
				if(str.charAt(left)==str.charAt(right)) {
					left++;
					right--;
				}else {
					chk = true;
					tl = left+1;
					tr = right;
					while(tl<tr) {
						if(str.charAt(tl)==str.charAt(tr)) {
							tl++;
							tr--;
						}else {
							chk = false;
							break;
						}
					}
					if(chk) {
						k = 1;
						break;
					}
					chk = true;
					tl = left;
					tr = right-1;
					while(tl<tr) {
						if(str.charAt(tl)==str.charAt(tr)) {
							tl++;
							tr--;
						}else {
							chk = false;
							break;
						}
					}
					if(chk) {
						k = 1;
						break;
					}
					k = 2;
					break;
				}
			}
			sb.append(k+"\n");
		}
		System.out.println(sb);
	}
}
