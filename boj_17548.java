import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int sz;
		sz = br.readLine().length()-2;
		sb.append("h");
		while(sz-->0) sb.append("ee");
		sb.append("y");
		System.out.println(sb);
	}
}
