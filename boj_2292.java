import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long n = Long.parseLong(br.readLine())-1;
        long t = (long)Math.ceil((Math.sqrt(9+12*n)-3)/6);
        System.out.println(t+1);
    }
}
