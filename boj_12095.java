import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String[] str = {
                "0 0 0 0 0 7 0 0 3",
                "0 0 1 0 0 0 9 0 0",
                "0 0 0 0 9 0 0 0 2",
                "0 3 0 0 0 0 0 0 1",
                "0 2 0 0 0 0 0 0 9",
                "0 0 0 9 0 0 0 0 0",
                "0 0 0 0 0 0 0 9 0",
                "0 1 0 5 0 0 0 0 0",
                "9 0 0 0 0 0 0 0 6"};
        for (int i = 0; i < 9; i++) sb.append(str[i] + "\n");
        System.out.println(sb);
    }
}
