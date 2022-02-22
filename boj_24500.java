import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		long n = Long.parseLong(br.readLine());
		if (n == 1) {
			System.out.println("1\n1");
			return;
		}
		long tmp = 1;
		while (true) {
			if (n <= tmp) {
				if (n == tmp) {
					sb.append("2\n" + (n - 1) + "\n" + n);
				} else if (n == tmp - 1) {
					sb.append("1\n" + n);
				} else {
					sb.append("2\n");
					sb.append((tmp - 1 - n) + "\n");
					sb.append(n);
				}
				break;
			}
			tmp *= 2;
		}
		System.out.println(sb);
	}
}
