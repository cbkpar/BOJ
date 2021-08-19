import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,m,i;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		if(n==2) {
			sb.append("YES\n");
			for(i=0;i<5;i++) sb.append("swap 1 2\n");
		}else if(n==3) {
			sb.append("NO\n");
		}else {
			sb.append("YES\n");
			if(m==1) {
				sb.append("swap 1 2\n");
				sb.append("reverse 3 "+n+"\n");
				sb.append("reverse 2 "+n+"\n");
			}else if(m==n-1){
				sb.append("swap "+(n-1)+" "+n+"\n");
				sb.append("reverse 1 "+(n-2)+"\n");
				sb.append("reverse 1 "+(n-1)+"\n");
			}else {
				sb.append("reverse 1 "+m+"\n");
				sb.append("reverse "+(m+1)+" "+n+"\n");
				sb.append("reverse 1 "+n+"\n");
			}
			sb.append("swap 1 2\nswap 1 2\n");
		}
		System.out.println(sb);
	}
}
