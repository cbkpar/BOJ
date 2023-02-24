import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        String strInput;
        while ((strInput = br.readLine()) != null) {
            StringTokenizer st = new StringTokenizer(strInput, " ");
            int iSize = st.countTokens();
            int ArrNumber[] = new int[iSize];
            for(int i=0;i<iSize;++i)
            {
                ArrNumber[i] = Integer.parseInt(st.nextToken());
            }
            for(int i=0;i<iSize;++i)
            {
                int iTemp = ArrNumber[i];
                if(i>0) iTemp *= ArrNumber[i-1];
                if(i<iSize-1) iTemp *= ArrNumber[i+1];
                sb.append(iTemp+(i==iSize-1?"\n":" "));
            }
        }
        System.out.println(sb);
    }
}
