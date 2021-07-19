import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,i;
		int[] a = new int[10001];
		n = Integer.parseInt(br.readLine());
		while(n-->0) a[Integer.parseInt(br.readLine())]++;
		for(i=1;i<=10000;i++) while(a[i]-->0) sb.append(i+"\n");
		System.out.println(sb);
	}
}
