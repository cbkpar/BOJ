import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i;
		n = Integer.parseInt(br.readLine());
		int[] X = new int[n];
		int[] Y = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(i=0;i<n;i++) X[i] = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		for(i=0;i<n;i++) Y[i] = Integer.parseInt(st.nextToken());
		Arrays.sort(X);
		Arrays.sort(Y);
		boolean chk = true;
		for(i=0;i<n;i++) {
			if(X[i]>Y[i]) {
				chk = false;
				break;
			}
		}
		System.out.println(chk?"DA":"NE");
	}
}
