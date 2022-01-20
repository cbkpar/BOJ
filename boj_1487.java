import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        long[][] arr = new long[n][2];
        for(int i=0;i<n;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            arr[i][0] = Long.parseLong(st.nextToken());
            arr[i][1] = Long.parseLong(st.nextToken());
        }
        long mx = 0;
        long num = Integer.MAX_VALUE;
        for(int i=0;i<n;i++){
            long cost = arr[i][0];
            long tmp = 0;
            for(int j=0;j<n;j++){
                if(cost<=arr[j][0]&&cost-arr[j][1]>0) tmp += cost-arr[j][1];
            }
            if(tmp==0) continue;
            if(tmp>mx){
                mx = tmp;
                num = cost;
            }else if(tmp==mx){
                num = Math.min(num,cost);
            }
        }
        System.out.println(num==Integer.MAX_VALUE?0:num);
    }
}
