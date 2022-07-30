import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int iN = Integer.parseInt(st.nextToken());
        double dCost = Double.parseDouble(st.nextToken());
        int iTotal = 0;
        int iBedRoom = 0;
        int iBalcony = 0;
        for (int i = 0; i < iN; ++i) {
            st = new StringTokenizer(br.readLine());
            int iNumber = Integer.parseInt(st.nextToken());
            String strItem = st.nextToken();
            iTotal += iNumber;
            if (strItem.equals("bedroom")) {
                iBedRoom += iNumber;
            }
            if (strItem.equals("balcony")) {
                iBalcony += iNumber;
            }
        }
        System.out.println(iTotal);
        System.out.println(iBedRoom);
        System.out.println(((double) iTotal - (double) iBalcony / 2) * dCost);
    }
}
