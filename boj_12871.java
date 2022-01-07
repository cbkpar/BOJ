import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String A = br.readLine();
        String B = br.readLine();
        String fA = "";
        String fB = "";
        for (int i = 0; i < B.length(); i++) fA += A;
        for (int i = 0; i < A.length(); i++) fB += B;
        System.out.println(fA.equals(fB) ? "1" : "0");
    }
}
