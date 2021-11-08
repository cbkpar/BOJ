import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        BigInteger[] arr = new BigInteger[251];
        arr[0] = new BigInteger("1");
        arr[1] = new BigInteger("1");
        for (int i = 2; i < 251; i++) arr[i] = arr[i - 1].add(arr[i - 2].multiply(new BigInteger("2")));
        String str = "";
        while ((str = br.readLine()) != null) sb.append(arr[Integer.parseInt(str)].toString() + "\n");
        System.out.println(sb);
    }
}
