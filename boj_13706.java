import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BigInteger num = new BigInteger(br.readLine());
		BigInteger l = new BigInteger("1");
		BigInteger r = num;
		while(true) {
			BigInteger m = l.add(r).divide(new BigInteger("2"));
			if(num.compareTo(m.pow(2))==0) {
				System.out.println(m);
				return;
			}else if(num.compareTo(m.pow(2))>0) {
				l = m.add(new BigInteger("1"));
			}else {
				r = m;
			}
		}
	}
}
