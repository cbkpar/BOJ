import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i;
		boolean chk = false;
		n = Integer.parseInt(br.readLine());
		if(n==0) {
			System.out.println("0\n0");
			return;
		}
		if(n<0) {
			chk = true;
			n = Math.abs(n);
		}
		int[] arr = new int[n+1];
		arr[1] = 1;
		for(i=2;i<=n;i++) arr[i] = (arr[i-1] + arr[i-2])%1000000000;
		System.out.println((chk&&n%2==0?"-1":"1")+"\n"+arr[n]);
	}
}
