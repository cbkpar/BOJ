import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	static int n;
	static long ans;
	static String str;
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		str = br.readLine();
		ans = Integer.MIN_VALUE;
		brute(0,str.charAt(0)-'0');
		if(n>=3) {
			if(str.charAt(2)=='+') {
				brute(1,((str.charAt(0)-'0')+(str.charAt(2)-'0')));
			}else if(str.charAt(2)=='-') {
				brute(1,((str.charAt(0)-'0')-(str.charAt(2)-'0')));
			}else if(str.charAt(2)=='*') {
				brute(1,((str.charAt(0)-'0')*(str.charAt(2)-'0')));
			}
		}
		System.out.println(ans);
	}
	
	static void brute(int k, long s) {
		if(2*k+1==n) {
			ans = Math.max(ans, s);
			return;
		}
		if(str.charAt(2*k+1)=='+') {
			brute(k+1,s+(str.charAt(2*k+2)-'0'));
			if(2*k+5<=n&&str.charAt(2*k+3)=='+') brute(k+2,s+((str.charAt(2*k+2)-'0')+(str.charAt(2*k+4)-'0')));
			if(2*k+5<=n&&str.charAt(2*k+3)=='-') brute(k+2,s+((str.charAt(2*k+2)-'0')-(str.charAt(2*k+4)-'0')));
			if(2*k+5<=n&&str.charAt(2*k+3)=='*') brute(k+2,s+((str.charAt(2*k+2)-'0')*(str.charAt(2*k+4)-'0')));
		}else if(str.charAt(2*k+1)=='-') {
			brute(k+1,s-(str.charAt(2*k+2)-'0'));
			if(2*k+5<=n&&str.charAt(2*k+3)=='+') brute(k+2,s-((str.charAt(2*k+2)-'0')+(str.charAt(2*k+4)-'0')));
			if(2*k+5<=n&&str.charAt(2*k+3)=='-') brute(k+2,s-((str.charAt(2*k+2)-'0')-(str.charAt(2*k+4)-'0')));
			if(2*k+5<=n&&str.charAt(2*k+3)=='*') brute(k+2,s-((str.charAt(2*k+2)-'0')*(str.charAt(2*k+4)-'0')));
		}else if(str.charAt(2*k+1)=='*') {
			brute(k+1,s*(str.charAt(2*k+2)-'0'));
			if(2*k+5<=n&&str.charAt(2*k+3)=='+') brute(k+2,s*((str.charAt(2*k+2)-'0')+(str.charAt(2*k+4)-'0')));
			if(2*k+5<=n&&str.charAt(2*k+3)=='-') brute(k+2,s*((str.charAt(2*k+2)-'0')-(str.charAt(2*k+4)-'0')));
			if(2*k+5<=n&&str.charAt(2*k+3)=='*') brute(k+2,s*((str.charAt(2*k+2)-'0')*(str.charAt(2*k+4)-'0')));
		}
		
	}
}
