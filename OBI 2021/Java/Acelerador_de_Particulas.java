import java.util.Scanner;

// Funcionou 100% no site da OBI solução correta

public class Acelerador_de_Particulas{

    public static void main(String[] args) {
        
        int quilometros, emissor;
        Scanner ler = new Scanner(System.in);

        quilometros = ler.nextInt();

        emissor = quilometros - 3;

        while(true){
            if(emissor <= 3){

                System.out.println("1");
                break;
            }
    
            else if(emissor <= 4){
                
                System.out.println("2");
                break;
            }
    
            else if(emissor <= 5){
    
                System.out.println("3");
                break;
            }
    
            else{
    
                emissor = emissor - 8;
            }
        }
    }
}