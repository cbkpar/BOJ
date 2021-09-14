import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int m,n,k,i,t;
		StringTokenizer st = new StringTokenizer(br.readLine());
		m = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		double[] arr = new double[k+1];
		for(i=1;i<=k;i++) arr[i] = Double.parseDouble(br.readLine());
		for(i=1;i<=k;i++) arr[i] += arr[i-1];
		t = 0;
		for(i=n;i<=k;i++) {
			if((arr[i]-arr[i-m])*n>(arr[i]-arr[i-n])*m) {
				if(t==1) continue;
				sb.append("BUY ON DAY "+i+"\n");
				t = 1;
			}else {
				if(t==2) continue;
				sb.append("SELL ON DAY "+i+"\n");
				t = 2;
			}
		}
		System.out.println(sb);
	}
}
