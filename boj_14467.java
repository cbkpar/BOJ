import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,a,b,s;
		int[] arr = new int[11];
		Arrays.fill(arr, -1);
		s = 0;
		n = Integer.parseInt(br.readLine());
		while(n-->0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			if(arr[a]!=-1) if(arr[a]!=b) s++; 
			arr[a] = b;
		}
		System.out.println(s);
	}
}
