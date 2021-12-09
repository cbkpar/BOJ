import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String[] arr = new String[13];
        String A = "-";
        String B = " ";
        arr[0] = "-";
        for (int i = 1; i <= 12; i++) {
            arr[i] = A = A + B + A;
            B = B + B + B;
        }
        String str = "";
        while ((str = br.readLine()) != null) {
            int n = Integer.parseInt(str);
            sb.append(arr[n]+"\n");
        }
        System.out.println(sb);
    }
}
