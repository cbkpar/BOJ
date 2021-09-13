import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		int n,sz,i,j;
		sz = str.length();
		int[] arr = new int[sz+1];
		for(i=1;i<=sz;i++) arr[i] = str.charAt(i-1)-'0';
		for(i=1;i<=sz;i++) arr[i] += arr[i-1];
		for(i=(sz/2)*2;i>=2;i-=2) {
			n = i/2;
			for(j=i;j<=sz;j++) {
				if(arr[j]-arr[j-n]==arr[j-n]-arr[j-i]) {
					System.out.println(i);
					return;
				}
			}
		}
	}
}
