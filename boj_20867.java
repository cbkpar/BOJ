import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        Double m = Double.parseDouble(st.nextToken());
        Double s = Double.parseDouble(st.nextToken());
        Double g = Double.parseDouble(st.nextToken());
        st = new StringTokenizer(br.readLine());
        Double a = Double.parseDouble(st.nextToken());
        Double b = Double.parseDouble(st.nextToken());
        st = new StringTokenizer(br.readLine());
        Double l = Double.parseDouble(st.nextToken());
        Double r = Double.parseDouble(st.nextToken());
        if (l / a + m / g > r / b + m / s) {
            System.out.println("latmask");
        } else {
            System.out.println("friskus");
        }
    }
}
