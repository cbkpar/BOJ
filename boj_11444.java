import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int i,j,k;
		long n;
		long[][] narr = new long[2][2];
		long[][] tarr = new long[2][2];
		n = Long.parseLong(br.readLine());
		n--;
		narr[0][0] = narr[1][1] = 1;
		tarr[0][0] = tarr[0][1] = tarr[1][0] = 1;
		while(n>0) {
			if(n%2==1) {
				long[][] sarr = new long[2][2];
				for(i=0;i<2;i++) for(j=0;j<2;j++) for(k=0;k<2;k++) sarr[i][j] += narr[i][k]*tarr[k][j];
				for(i=0;i<2;i++) for(j=0;j<2;j++) narr[i][j] = sarr[i][j]%1000000007;
			}
			long[][] sarr = new long[2][2];
			for(i=0;i<2;i++) for(j=0;j<2;j++) for(k=0;k<2;k++) sarr[i][j] += tarr[i][k]*tarr[k][j];
			for(i=0;i<2;i++) for(j=0;j<2;j++) tarr[i][j] = sarr[i][j]%1000000007;
			n/=2;
		}
		System.out.println((narr[1][0]+narr[1][1])%1000000007);
		
	}
}
