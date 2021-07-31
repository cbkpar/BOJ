import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws Exception{		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		long a,b,t;
		StringTokenizer st = new StringTokenizer(br.readLine());
		a = Long.parseLong(st.nextToken());
		b = Long.parseLong(st.nextToken());
		t = a>b?gcd(b,a):gcd(a,b);
		System.out.println(a/t*b);
	}
	
	public static long gcd(long a, long b) {
		if(b%a==0) return a;
		return gcd(b%a,a);
	}
}
