import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		double a,b,c,i,j,k,m;
		StringTokenizer st = new StringTokenizer(br.readLine());
		a = Double.parseDouble(st.nextToken());
		b = Double.parseDouble(st.nextToken());
		c = Double.parseDouble(st.nextToken());
		st = new StringTokenizer(br.readLine());
		i = Double.parseDouble(st.nextToken());
		j = Double.parseDouble(st.nextToken());
		k = Double.parseDouble(st.nextToken());
		m = a/i;
		m = Math.min(m, b/j);
		m = Math.min(m, c/k);
		System.out.println((a-i*m)+" "+(b-j*m)+" "+(c-k*m));
	}
}
