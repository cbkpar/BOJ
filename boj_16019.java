import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int i,j;
		int[] arr = new int[5];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(i=1;i<=4;i++) arr[i] = Integer.parseInt(st.nextToken());
		for(i=1;i<=4;i++) arr[i] += arr[i-1];
		
		for(i=0;i<5;i++) {
			for(j=0;j<5;j++) {
				sb.append(Math.abs(arr[i]-arr[j]));
				if(j!=4) sb.append(" ");
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}
}
