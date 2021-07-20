import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,x,y;
		n = Integer.parseInt(br.readLine());
		x = Math.max((int)Math.sqrt(n)-1,1);
		y = Math.max(n/(x+1)+(n%(x+1)!=0?1:0)-1,1);
		System.out.println((x+y)*2);
	}
}
