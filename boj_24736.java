import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int A = 0;
        A += Integer.parseInt(st.nextToken()) * 6;
        A += Integer.parseInt(st.nextToken()) * 3;
        A += Integer.parseInt(st.nextToken()) * 2;
        A += Integer.parseInt(st.nextToken()) * 1;
        A += Integer.parseInt(st.nextToken()) * 2;
        st = new StringTokenizer(br.readLine());
        int B = 0;
        B += Integer.parseInt(st.nextToken()) * 6;
        B += Integer.parseInt(st.nextToken()) * 3;
        B += Integer.parseInt(st.nextToken()) * 2;
        B += Integer.parseInt(st.nextToken()) * 1;
        B += Integer.parseInt(st.nextToken()) * 2;
        System.out.println(A + " " + B);
    }
}
