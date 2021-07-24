import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int sz,i;
		String str;
		HashMap<Character,Character> arr = new HashMap<Character,Character>();
		arr.put('1','`');
		arr.put('2','1');
		arr.put('3','2');
		arr.put('4','3');
		arr.put('5','4');
		arr.put('6','5');
		arr.put('7','6');
		arr.put('8','7');
		arr.put('9','8');
		arr.put('0','9');
		arr.put('-','0');
		arr.put('=','-');
		arr.put('W','Q');
		arr.put('E','W');
		arr.put('R','E');
		arr.put('T','R');
		arr.put('Y','T');
		arr.put('U','Y');
		arr.put('I','U');
		arr.put('O','I');
		arr.put('P','O');
		arr.put('[','P');
		arr.put(']','[');
		arr.put('\\',']');
		arr.put('S','A');
		arr.put('D','S');
		arr.put('F','D');
		arr.put('G','F');
		arr.put('H','G');
		arr.put('J','H');
		arr.put('K','J');
		arr.put('L','K');
		arr.put(';','L');
		arr.put('\'',';');
		arr.put('X','Z');
		arr.put('C','X');
		arr.put('V','C');
		arr.put('B','V');
		arr.put('N','B');
		arr.put('M','N');
		arr.put(',','M');
		arr.put('.',',');
		arr.put('/','.');
		arr.put(' ',' ');
		while((str=br.readLine())!=null) {
			sz = str.length();
			for(i=0;i<sz;i++) sb.append(arr.get(str.charAt(i)));
			sb.append("\n");
		}
		System.out.println(sb);
	}
}
