import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int w,h,x,y,t;
		StringTokenizer st = new StringTokenizer(br.readLine());
		w = Integer.parseInt(st.nextToken());
		h = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		x = Integer.parseInt(st.nextToken());
		y = Integer.parseInt(st.nextToken());
		t = Integer.parseInt(br.readLine());
		x = (x+t)%(w*2);
		if(x>w) x = 2*w-x;
		y = (y+t)%(h*2);
		if(y>h) y = 2*h-y;
		System.out.println(x+" "+y);
	}
}
