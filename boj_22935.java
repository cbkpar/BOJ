import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int t,n,i;
		t = Integer.parseInt(br.readLine());
		int[] arr = new int[4];
		while(t-->0) {
			n = Integer.parseInt(br.readLine());
			n = (n+27)%28+1;
			if(n>15) n = 30-n;
			for(i=0;i<4;i++) {
				arr[i] = n%2;
				n/=2;
			}
			for(i=3;i>=0;i--) sb.append(arr[i]==1?"딸기":"V");
			sb.append("\n");
		}
		System.out.println(sb);
	}
}
