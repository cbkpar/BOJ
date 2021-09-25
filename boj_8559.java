import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        if(str.length()==1&&str.charAt(0)=='0'){
            System.out.println("1");
            return;
        }
        int n;
        if(str.length()>2){
            n = Integer.parseInt(str.substring(str.length()-2));
        }else{
            n = Integer.parseInt(str);
        }
        if(n%4==0){
            System.out.println("6");
        }else if(n%4==1){
            System.out.println("2");
        }else if(n%4==2){
            System.out.println("4");
        }else{
            System.out.println("8");
        }
    }
}
