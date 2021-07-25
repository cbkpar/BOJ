import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int i,j;
		int[] arr = new int[16];
		String str = br.readLine();
		for(i=0;i<8;i++) arr[i*2] = str.charAt(i)-'0';
		str = br.readLine();
		for(i=0;i<8;i++) arr[i*2+1] = str.charAt(i)-'0';
		for(i=0;i<14;i++) for(j=0;j<15;j++) arr[j] = (arr[j]+arr[j+1])%10; 
		System.out.println(arr[0]+""+arr[1]);
	}
}
