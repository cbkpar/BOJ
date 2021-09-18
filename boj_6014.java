import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,k,t,q,i;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		int[] arr = new int[1200001];
		t = 0;
		for(i=1;i<=n;i++) {
			q = Integer.parseInt(br.readLine());
			while(q-->0) arr[t++] = i;
		}
		while(k-->0) sb.append(arr[Integer.parseInt(br.readLine())]+"\n");
		System.out.println(sb);
	}
}
