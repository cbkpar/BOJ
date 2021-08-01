import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n,i,j,t;
        n = Integer.parseInt(br.readLine());
        boolean[][] chk = new boolean[n][n];
        for(i=0;i<n;i++) {
        	String str = br.readLine();
        	for(j=0;j<n;j++) if(str.charAt(j)=='*') chk[i][j] = true;
        }
        for(i=0;i<n;i++) {
        	for(j=0;j<n;j++) {
        		if(chk[i][j]) {
        			sb.append((i+2)+" "+(j+1)+"\n");
        			t = 0;
        			while(true) {
        				if(j-t-1<0) break;
        				if(chk[i+1][j-t-1]) {
        					t++;
        				}else {
        					break;
        				}
        			}
        			sb.append(t+" ");
        			t = 0;
        			while(true) {
        				if(j+t+1>n-1) break;
        				if(chk[i+1][j+t+1]) {
        					t++;
        				}else {
        					break;
        				}
        			}
        			sb.append(t+" ");
        			t = 0;
        			while(true) {
        				if(chk[i+2+t][j]) {
        					t++;
        				}else {
        					break;
        				}
        			}
        			sb.append(t+" ");
        			i += t+2;
        			t = 0;
        			while(true) {
        				if(i+t>n-1) break;
        				if(chk[i+t][j-1]) {
        					t++;
        				}else {
        					break;
        				}
        			}
        			sb.append(t+" ");
        			t = 0;
        			while(true) {
        				if(i+t>n-1) break;
        				if(chk[i+t][j+1]) {
        					t++;
        				}else {
        					break;
        				}
        			}
        			sb.append(t+" ");
        			System.out.println(sb);
        			return;
        		}
        	}
        }
	}
}
