import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int ta = Gettime(br.readLine());
		int tb = Gettime(br.readLine());
		int diff = (--tb-ta+86400)%86400+1;
		System.out.printf("%02d:%02d:%02d",diff/3600,(diff%3600)/60,diff%60);
	}
	
	static int Gettime(String str) {
		StringTokenizer st = new StringTokenizer(str,":");
		int time = 0;
		time += Integer.parseInt(st.nextToken())*3600;
		time += Integer.parseInt(st.nextToken())*60;
		time += Integer.parseInt(st.nextToken());
		return time;
	}
}
