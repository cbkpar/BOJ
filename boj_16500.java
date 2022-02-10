import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int sz = str.length();
        boolean[] chk = new boolean[sz];
        boolean[][] map = new boolean[sz + 1][sz + 1];
        int n = Integer.parseInt(br.readLine());
        while (n-- > 0) {
            String A = br.readLine();
            int Asz = A.length();
            for (int i = 0; i < sz - Asz + 1; i++) {
                boolean tmp = true;
                for (int j = 0; j < Asz; j++) {
                    if (str.charAt(i + j) == A.charAt(j)) continue;
                    tmp = false;
                    break;
                }
                if (tmp) map[i][i + Asz] = true;
            }
        }
        boolean[] ispossible = new boolean[sz+1];
        ispossible[0] = true;
        for(int i=0;i<sz;i++){
            if(ispossible[i]){
                for(int j=i;j<sz+1;j++){
                    if(map[i][j]) ispossible[j] = true;
                }
            }
        }
        System.out.println(ispossible[sz] ? "1" : "0");
    }
}
