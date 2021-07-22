import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,i;
		n = Integer.parseInt(br.readLine());
		for(i=n;i>=0;i--) {
			if(i!=n) sb.append("\n");
			if(i>=3) {
				sb.append(i+" bottles of beer on the wall, "+i+" bottles of beer.\n");
				sb.append("Take one down and pass it around, "+(i-1)+" bottles of beer on the wall.\n");
			}else if(i==2) {
				sb.append(i+" bottles of beer on the wall, "+i+" bottles of beer.\n");
				sb.append("Take one down and pass it around, "+(i-1)+" bottle of beer on the wall.\n");
			}else if(i==1){
				sb.append(i+" bottle of beer on the wall, "+i+" bottle of beer.\n");
				sb.append("Take one down and pass it around, no more bottles of beer on the wall.\n");
			}else {
				sb.append("No more bottles of beer on the wall, no more bottles of beer.\n");
				sb.append("Go to the store and buy some more, "+n+" bottle"+(n>1?"s":"")+" of beer on the wall.\n");
				
			}
		}
		System.out.println(sb);
	}
}
