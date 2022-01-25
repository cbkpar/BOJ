import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {


    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        BigInteger money = new BigInteger(st.nextToken());
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(br.readLine());
        for(int i=0;i<n-1;i++){
            if(arr[i]<arr[i+1]){
                BigInteger coin = money.divide(new BigInteger(Integer.toString(arr[i])));
                money = money.remainder(new BigInteger(Integer.toString(arr[i])));
                money = money.add(coin.multiply(new BigInteger(Integer.toString(arr[i+1]))));
            }
        }
        System.out.println(money);
    }
}
