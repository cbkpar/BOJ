import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int t,sz,i;
		t = Integer.parseInt(br.readLine());
		while(t-->0) {
			String str = br.readLine().trim();
			sz = str.length();
			for(i=0;i<sz;i++) if(str.charAt(i)<'0'||str.charAt(i)>'9') break;
			if(i==sz&&sz!=0) {
				BigInteger big = new BigInteger(str);
				sb.append(big+"\n");
			}else {
				sb.append("invalid input\n");
			}
		}
		System.out.println(sb);
	}
}
