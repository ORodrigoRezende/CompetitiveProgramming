import java.io.IOException;
import java.util.Scanner;
// arquivo com nome 1024 mas para rodar na plataforma tem que ser main
public class Main{
    public static void main(String[] args) throws IOException{
        Scanner scn = new Scanner(System.in);
        int x = scn.nextInt();
        scn.nextLine();
        for(int i = 0; i<x;i++){
            String string = scn.nextLine();
            char[] s = string.toCharArray();
            for(int j = 0;j<s.length;j++){
                if((s[j]>='a' && s[j]<='z')|| (s[j]>='A' && s[j]<='Z'))
                s[j] = (char)(s[j] + 3);
            }
            for(int j = 0,k=s.length-1;j<s.length/2;j++,k--){
                char c = s[j];
                s[j] = s[k];
                s[k] = c;
            }
            for(int j = s.length/2;j<s.length;j++){
                s[j] = (char) (s[j] - 1);
            }
            
            System.out.println(s);
        }
        }
}