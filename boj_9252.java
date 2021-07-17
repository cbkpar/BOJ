import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int asz,bsz,i,j,s;
		String stra,strb;
		stra = br.readLine();
		strb = br.readLine();
		asz = stra.length();
		bsz = strb.length();
		int[][] lcs = new int[asz+1][bsz+1];
		for(i=0;i<asz;i++) {
			for(j=0;j<bsz;j++) {
				if(stra.charAt(i)==strb.charAt(j)) {
					lcs[i+1][j+1] = lcs[i][j]+1;
				}else {
					lcs[i+1][j+1] = Math.max(lcs[i][j+1], lcs[i+1][j]);
				}
			}
		}
		s = lcs[asz][bsz];
		sb.append(s+"\n");
        Stack<Character> stack = new Stack<>();
        i = asz;
        j = bsz;
        while(i>0&&j>0) {
        	if(lcs[i-1][j]==lcs[i][j]) {
        		i--;
        		continue;
        	}
        	if(lcs[i][j-1]==lcs[i][j]) {
        		j--;
        		continue;
        	}
        	stack.add(stra.charAt(i-1));
        	i--;
        	j--;
        }
        if(!stack.isEmpty()) {
        	while(!stack.isEmpty()) sb.append(stack.pop());
        	sb.append("\n");
        }
        System.out.println(sb);
	}
}
