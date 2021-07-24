import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeMap;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int s;
		String str;
		TreeMap<String,Integer> tree = new TreeMap<String,Integer>();
		s = 0;
		while((str=br.readLine())!=null) {
			if(tree.containsKey(str)) {
				tree.put(str, tree.get(str)+1);
			}else {
				tree.put(str, 1);
			}
			s++;
		}
		for(String name : tree.keySet()) sb.append(name+" "+String.format("%.4f", (double)tree.get(name)*100/(double)s)+"\n");
		System.out.println(sb);
	}
}
