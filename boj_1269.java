import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int a,b,i,s;
		HashMap<Integer,Boolean> map = new HashMap<>();
		StringTokenizer st = new StringTokenizer(br.readLine());
		s = a = Integer.parseInt(st.nextToken());
		b = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		for(i=0;i<a;i++) map.put(Integer.parseInt(st.nextToken()),true);
		st = new StringTokenizer(br.readLine());
		for(i=0;i<b;i++) {
			if(map.containsKey(Integer.parseInt(st.nextToken()))) {
				s--;
			}else {
				s++;
			}
		}
		System.out.println(s);
	}
}
