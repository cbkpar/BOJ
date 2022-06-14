import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int iN = Integer.parseInt(br.readLine());
        int[] arr = new int[iN + 1];
        arr[1] = arr[2] = 1;
        for (int i = 3; i <= iN; ++i) {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
        System.out.println(arr[iN] + " " + (iN - 2));
    }
}
