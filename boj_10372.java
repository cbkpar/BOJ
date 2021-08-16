import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int[] arr = {6,2,5,5,4,5,6,3,7,6};
		int n,i,j,t;
		n = Integer.parseInt(br.readLine());
		for(i=0;i<24;i++) {
			for(j=0;j<60;j++) {
				t = arr[i/10]+arr[i%10]+arr[j/10]+arr[j%10];
				if(t==n) {
					System.out.println((i/10)+""+(i%10)+":"+(j/10)+""+(j%10));
					return;
				}
			}
		}
		System.out.println("Impossible");
	}
}
