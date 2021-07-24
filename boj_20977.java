import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,i,sz;
		n = Integer.parseInt(br.readLine());
		int[] arr = new int[3];
		while(n-->0);
		String str = br.readLine();
		sz = str.length();
		for(i=0;i<sz;i++) {
			if(str.charAt(i)=='J') {
				arr[0]++;
			}else if(str.charAt(i)=='O') {
				arr[1]++;
			}else {
				arr[2]++;
			}
		}
		while(arr[0]-->0) sb.append("J");
		while(arr[1]-->0) sb.append("O");
		while(arr[2]-->0) sb.append("I");
		System.out.println(sb);
	}
}
