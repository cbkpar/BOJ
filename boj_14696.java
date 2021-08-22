import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int t,a,b,i;
		t = Integer.parseInt(br.readLine());
		while(t-->0) {
			int[] arr = new int[5];
			StringTokenizer st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			while(a-->0) arr[Integer.parseInt(st.nextToken())]++;
			st = new StringTokenizer(br.readLine());
			b = Integer.parseInt(st.nextToken());
			while(b-->0) arr[Integer.parseInt(st.nextToken())]--;
			for(i=4;i>=1;i--) {
				if(arr[i]>0) {
					sb.append("A\n");
					break;
				}else if(arr[i]<0) {
					sb.append("B\n");
					break;
				}
				if(i==1) {
					sb.append("D\n");
				}
			}
		}
		System.out.println(sb);
	}
}
