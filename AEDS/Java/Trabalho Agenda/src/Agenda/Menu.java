package Agenda;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Menu {

    Map<String,Registro> AgendaTelefonica = new HashMap<String,Registro>();

    public void Menuzinho(){

        int op;
        Scanner ler = new Scanner(System.in);
        ManipulacaoAgenda Manipula = new ManipulacaoAgenda();
        InteracaoUsuario interage = new InteracaoUsuario();
        Registro temp;

        do {

            System.out.println("\t+----------------------+");
            System.out.println("\t|  BEM-VINDO A AGENDA  |");
            System.out.println("\t+----------------------+");
            System.out.println("[1]Adicionar novo contato");
            System.out.println("[2]Remover contato existente");
            System.out.println("[3]Alterar contato existente");
            System.out.println("[4]Imprimir agenda");
            System.out.println("[0]Encerrar");
            System.out.print("> ");
            op = ler.nextInt();

            switch (op){

                case 1:

                    temp = Manipula.adicionaContato();
                    AgendaTelefonica.put(temp.getNumeroIdentificacao(),temp);

                    break;

                case 2:

                    Manipula.Imprimr(AgendaTelefonica);
                    Manipula.ApagarContato(interage.ObtemNumero(),AgendaTelefonica);

                    break;

                case 3:

                    Manipula.Imprimr(AgendaTelefonica);
                    Manipula.AlterarContato(interage.ObtemNumero(),AgendaTelefonica);

                    break;

                case 4:

                    Manipula.Imprimr(AgendaTelefonica);

                    break;

                case 0:

                    System.out.println("\t+---------------+");
                    System.out.println("\t| TCHAUZINHO :3 |");
                    System.out.println("\t+---------------+");

                    break;

                default:

                    System.out.println("Opcao invalida");

                    break;
            }

        }while (op != 0);
    }
}
