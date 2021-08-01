import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,t,i;
		n = Integer.parseInt(br.readLine());
		int[] arr = new int[100001];
		while(n-->0) arr[Integer.parseInt(br.readLine().replace(".", ""))]++;
		t = i = 0;
		while(true) {
			while(arr[i]-->0) {
				t++;
				sb.append(String.format("%d.%03d\n",i/1000,i%1000));
				if(t==7) {
					System.out.println(sb);
					return;
				}
			}
			i++;
		}
	}
}
