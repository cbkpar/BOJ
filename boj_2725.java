import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringBuilder sb = new StringBuilder();
    	int n,t,i;
    	int[] arr = new int[1001];
    	n = Integer.parseInt(br.readLine());
    	for(i=1;i<=1000;i++) {
    		arr[i] = arr[i-1] + eulerphi(i);
    	}
    	while(n-->0) {
    		t = Integer.parseInt(br.readLine());
    		sb.append((arr[t]*2+1)+"\n");
    	}
    	System.out.println(sb);
    }
    
	public static int eulerphi(int n) {
		int ans,sq,i;
		ans = n;
		sq = (int)Math.sqrt(ans);
		for(i=2;i<=sq;i++) {
			if(n%i==0) {
				ans /= i;
				ans *= i-1;
				while(n%i==0) n/=i;
			}
		}
		if(n!=1) {
			ans /= n;
			ans *= n-1;
		}
		return ans;
	}
}
