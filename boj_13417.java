import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String str = "";
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int i=0;i<n;i++){
                String tmp = st.nextToken();
                if(str.concat(tmp).compareTo(tmp.concat(str))>=0){
                    str = tmp.concat(str);
                }else{
                    str = str.concat(tmp);
                }
            }
            sb.append(str+"\n");
        }
        System.out.println(sb);
    }
}
