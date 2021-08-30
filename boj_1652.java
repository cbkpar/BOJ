import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
    public static void main(String args[]) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	int n = Integer.parseInt(br.readLine());
    	int[][][] map = new int[n][n][2];
    	for(int i=0;i<n;i++) {
    		String str = br.readLine();
    		for(int j=0;j<n;j++) if(str.charAt(j)=='.') map[i][j][0] = map[i][j][1] = 1;
    	}
    	for(int i=0;i<n;i++) {
    		for(int j=1;j<n;j++) {
    			if(map[i][j][0]==1) if(map[i][j-1][0]>0) {
    				map[i][j-1][0] = 0;
    				map[i][j][0] = 2;
    			}
    		}
    	}
    	for(int i=0;i<n;i++) {
    		for(int j=1;j<n;j++) {
    			if(map[j][i][1]==1) if(map[j-1][i][1]>0) {
    				map[j-1][i][1] = 0;
    				map[j][i][1] = 2;
    			}
    		}
    	}
    	int a = 0;
    	for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(map[i][j][0]==2) a++;
    	int b = 0;
    	for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(map[i][j][1]==2) b++;
    	System.out.println(a+" "+b);
    }
}
