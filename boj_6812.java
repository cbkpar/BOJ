import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        int time = (n/100)*60+n%100;
        sb.append(convert(time)+" in Ottawa\n");
        sb.append(convert((time-180))+" in Victoria\n");
        sb.append(convert((time-120))+" in Edmonton\n");
        sb.append(convert((time-60))+" in Winnipeg\n");
        sb.append(convert((time))+" in Toronto\n");
        sb.append(convert((time+60))+" in Halifax\n");
        sb.append(convert((time+90))+" in St. John's\n");
        System.out.println(sb);
    }

    private static int convert(int t){
        t = (t+1440)%1440;
        return (t/60)*100+t%60;
    }
}
