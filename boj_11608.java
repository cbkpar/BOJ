import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int[] cnt = new int[26];
		int i,sz;
		String str = br.readLine();
		sz = str.length();
		for(i=0;i<sz;i++) cnt[str.charAt(i)-'a']++;
		PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
		for(i=0;i<26;i++) if(cnt[i]!=0) pq.add(cnt[i]);
		System.out.println(pq.size()>2?sz-pq.poll()-pq.poll():0);
	}
}
