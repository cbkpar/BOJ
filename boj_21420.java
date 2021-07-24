import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,s,i;
		n = Integer.parseInt(br.readLine());
		s = 0;
		for(i=0;i<n;i++) s += Integer.parseInt(br.readLine());
		System.out.println(Math.min(s, n-s));
	}
}
