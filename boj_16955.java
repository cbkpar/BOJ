import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static int[][] map = new int[10][10];

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for(int i=0;i<10;i++){
            String str = br.readLine();
            for(int j=0;j<10;j++){
                if(str.charAt(j)=='X'){
                    map[i][j] = 1;
                }else if(str.charAt(j)=='O'){
                    map[i][j] = 2;
                }
            }
        }
        int mxscore = 0;
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(map[i][j]==0){
                    map[i][j] = 1;
                    mxscore= Math.max(mxscore, gamechk(i,j));
                    map[i][j]=0;
                }
            }
        }
        System.out.println(mxscore>=4?"1":"0");
    }

    public static int gamechk(int y, int x) {
        int tmp = 0;
        tmp = Math.max(tmp,dirchk(y,x,0,-1)+dirchk(y,x,0,1));
        tmp = Math.max(tmp,dirchk(y,x,-1,0)+dirchk(y,x,1,0));
        tmp = Math.max(tmp,dirchk(y,x,-1,-1)+dirchk(y,x,1,1));
        tmp = Math.max(tmp,dirchk(y,x,-1,1)+dirchk(y,x,1,-1));
        return tmp;
    }

    public static int dirchk(int y, int x, int ty, int tx){
        int tmp = 1;
        while(true){
            int ny = y + ty * tmp;
            int nx = x + tx * tmp;
            if(ny<0||ny>9||nx<0||nx>9) break;
            if(map[ny][nx]!=1) break;
            tmp++;
        }
        return tmp-1;
    }
}
