import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int k,i,o,ans;
		String str = "";
		k = Integer.parseInt(br.readLine());
		int[] arr = new int[6];
		for(i=0;i<6;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			str = str + st.nextToken();
			arr[i] = Integer.parseInt(st.nextToken());
		}
		str = str + str;
		if(str.contains("423131")||str.contains("413232")) {
			for(o=0;o<6;o++) if(str.charAt(o)=='4') break;
			ans = arr[o%6]*arr[(o+1)%6]-arr[(o+3)%6]*arr[(o+4)%6];
		}else if(str.contains("141423")||str.contains("242413")) {
			for(o=0;o<6;o++) if(str.charAt(o)=='3') break;
			ans = arr[o%6]*arr[(o+5)%6]-arr[(o+2)%6]*arr[(o+3)%6];
		}else if(str.contains("324141")||str.contains("314242")) {
			for(o=0;o<6;o++) if(str.charAt(o)=='3') break;
			ans = arr[o%6]*arr[(o+1)%6]-arr[(o+3)%6]*arr[(o+4)%6];
		}else {
			for(o=0;o<6;o++) if(str.charAt(o)=='4') break;
			ans = arr[o%6]*arr[(o+5)%6]-arr[(o+2)%6]*arr[(o+3)%6];
		}
		System.out.println(Math.abs(ans*k));
	}
}
