import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int[] arr = {1,2,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0};
		int n,i,sz,s;
		n = Integer.parseInt(br.readLine());
		while(n-->0) {
			String str = br.readLine();
			sz = str.length();
			s = 0;
			for(i=0;i<sz;i++) if(str.charAt(i)>='A'&&str.charAt(i)<='Z') s += arr[str.charAt(i)-'A'];
			sb.append(s+"\n");
		}
		System.out.println(sb);
	}
}
