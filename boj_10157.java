import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int c,r,k,t;
		c = Integer.parseInt(st.nextToken());
		r = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(br.readLine());
		if(k>c*r) {
			System.out.println("0");
		}else {
			t = 1;
			while(true) {
				if(c==1&&r==1) break;
				if(k>(c+r-2)*2){
					t++;
					k-=(c+r-2)*2;
					c-=2;
					r-=2;
				}else {
					break;
				}
			}
			if(k<=r) {
				System.out.println(t+" "+(t+k-1));
			}else if(k<=r+c-1){
				k -= r;
				System.out.println((t+k)+" "+(t+r-1));
			}else if(k<=2*r+c-2) {
				k -= r+c-2;
				System.out.println((t+c-1)+" "+(t+r-k));
			}else {
				k -= r*2+c-2;
				System.out.println((t+c-k-1)+" "+t);
			}
		}
	}
}
