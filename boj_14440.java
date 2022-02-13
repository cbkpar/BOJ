import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());
        int A0 = Integer.parseInt(st.nextToken());
        int A1 = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        if(n==0){
            System.out.println(String.format("%02d", A0));
        }else if(n==1){
            System.out.println(String.format("%02d", A1));
        }else{
            int[][] chk = new int[100][100];
            int[] arr = new int[20004];
            arr[0] = A0;
            arr[1] = A1;
            for(int i=2;i<20004;i++){
                if(chk[arr[i-1]][arr[i-2]]!=0){
                    int cycle = i-chk[arr[i-1]][arr[i-2]];
                    if((n-i)/cycle>=1) n-=cycle*((n-i)/cycle);
                }
                arr[i] = (arr[i-1]*x+arr[i-2]*y)%100;
                chk[arr[i-1]][arr[i-2]]= i;
                if(i==n){
                    System.out.println(String.format("%02d", arr[i]));
                    return;
                }
            }
        }
    }
}
