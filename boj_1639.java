import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int i,j,sz;
		String str = br.readLine();
		sz = str.length();
		int[] arr = new int[sz+1];
		for(i=1;i<=sz;i++) arr[i] = arr[i-1] + str.charAt(i-1)-'0';
		for(i=sz/2;i>0;i--) {
			for(j=i;j<=sz-i;j++) {
				if(arr[j]-arr[j-i]==arr[j+i]-arr[j]) {
					System.out.println(i*2);
					return;
				}
			}
		}
		System.out.println("0");
	}
}
