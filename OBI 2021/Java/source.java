import java.util.Scanner;

public class source {
    public static void main(String[] args) {
        
        int nParticipantes, TamP = 0, TamM = 0,TamPDisponivel,TamMDisponivel;
        Scanner ler = new Scanner(System.in);

        nParticipantes = ler.nextInt();

        int []nCamisas = new int [nParticipantes];

        for(int i = 0; i < nParticipantes; i++){
            nCamisas[i] = ler.nextInt();

            if(nCamisas[i] == 1) TamP++;

            else TamM++;
        }

        TamPDisponivel = ler.nextInt();
        TamMDisponivel = ler.nextInt();

        if(TamMDisponivel == TamM && TamPDisponivel == TamP){ System.out.println("S");}

        else { System.out.println("N");}
    }    
}
