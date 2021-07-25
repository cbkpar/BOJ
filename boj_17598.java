import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int i,s;
		s = 0;
		for(i=0;i<9;i++) if(br.readLine().equals("Lion")) s++;
		System.out.println(s>4?"Lion":"Tiger");
	}
}
