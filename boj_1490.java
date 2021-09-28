import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int sz, i, t, k;
		long n;
		String str = br.readLine();
		t = 1;
		sz = str.length();
		for (i = 0; i < sz; i++) {
			k = str.charAt(i) - '0';
			if (k == 0)
				continue;
			if (t > k) {
				t *= k / gcd(k, t);
			} else {
				t *= k / gcd(t, k);
			}
		}
		n = Long.parseLong(str);
		if (n % t == 0) {
			System.out.println(n);
			return;
		}
		k = 10;
		while (true) {
			for (i = 0; i < k; i++) {
				if ((n * k + i) % t == 0) {
					System.out.println((n * k + i));
					return;
				}
			}
			k *= 10;
		}
	}

	public static int gcd(int a, int b) {
		if (a % b == 0)
			return b;
		return gcd(b, a % b);
	}
}
