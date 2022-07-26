package Agenda;

import java.util.Map;
import java.util.Scanner;

public class ManipulacaoAgenda {

    InteracaoUsuario interage = new InteracaoUsuario();

    public Registro adicionaContato(){

        Registro novoContato = new Registro();

        novoContato.setNome(interage.ObtemNome());

        Scanner ler = new Scanner(System.in);
        String op;

        System.out.println("A pessoa é Juridica(j) ou Fisica(f): ");
        op = ler.next();

        if (op.equals("j") || op.equals("J")){

            novoContato.setPessoa(new PessoaJuridica(interage.ObtemNumero()));
        }

        else if (op.equals("f") || op.equals("F")){

            novoContato.setPessoa(new PessoaFisica(interage.ObtemNumero()));
        }

        else System.out.println("opção inválida");

        boolean loop = false;

        while (!loop){

            novoContato.adicionaTelefone(interage.ObtemTelefone());
            System.out.println("Deseja adicionar mais algum numero? \nSim[s]\nNão[n]\n>");
            op = ler.next();

            if (op.equals("n") || op.equals("N")) loop = true;

            else if(op.equals("s") || op.equals("S")) loop = false;

            else {

                System.out.println("opção invalida");
                loop = true;
            }
        }

        String logradouro;
        int numero;
        String complemento;
        String bairro;
        String cidade;
        String estado;
        String CEP;

        loop = false;

        while (!loop){

            System.out.println("Digite o logradouro: ");
            logradouro = ler.next();
            ler.nextLine();
            System.out.println("Digite o numero: ");
            numero = ler.nextInt();
            ler.nextLine();
            System.out.println("Digite o complemento: ");
            complemento = ler.next();
            ler.nextLine();
            System.out.println("Digite o bairro: ");
            bairro = ler.next();
            ler.nextLine();
            System.out.println("Digite a cidade: ");
            cidade = ler.next();
            ler.nextLine();
            System.out.println("Digite o estado: ");
            estado = ler.next();
            ler.nextLine();
            System.out.println("Digite o CEP: ");
            CEP = ler.next();
            ler.nextLine();
            novoContato.adicionaEndereco(logradouro,numero,complemento,bairro,cidade,estado,CEP);
            System.out.println("Deseja adicionar mais algum endereço?\nSim[s]\nNão[n]");
            op = ler.next();
            ler.nextLine();

            if (op.equals("n") || op.equals("N")) loop = true;
            else if (op.equals("s") || op.equals("S")) loop = false;
            else {

                System.out.println("opcao inválida!");
                loop = true;
            }
        }

        return novoContato;
    }

    public void ApagarContato(String CadastroPessoa, Map<String,Registro> Agenda){

        Agenda.remove(CadastroPessoa);

    }

    public void AlterarContato(String CadastroPessoa, Map<String,Registro> Agenda){

        Scanner ler = new Scanner(System.in);
        int op;

        System.out.println("\n\tO que deseja alterar em " + Agenda.get(CadastroPessoa).getNome() + " :\n");
        System.out.println("[1]Nome\n[2]Telefone\n[3]Endereço\n[0]Nada\n> ");
        op = ler.nextInt();

        switch (op){
            case 1:

                Agenda.get(CadastroPessoa).setNome(interage.ObtemNome());

                break;

            case 2:

                System.out.println("\n\tO que deseja fazer?\n");
                System.out.println("[1]Adicionar novo numero\n[2]Remover um numero\n[0]Nada\n> ");
                op = ler.nextInt();

                switch (op){

                    case 1:

                        Agenda.get(CadastroPessoa).adicionaTelefone(interage.ObtemTelefone());
                        break;
                    case 2:

                        Agenda.get(CadastroPessoa).removeTelefone(interage.ObtemTelefone());
                        break;

                    case 0:

                        System.out.println("\nTchauzinho :3");

                        break;

                    default:

                        System.out.println("Essa opção não existe!");

                        break;
                }

                break;

            case 3:

                System.out.println("\n\tO que deseja fazer?");
                System.out.println("[1]Adicionar novo endereço\n[2]Remover um endereço\n[0]Nada\n> ");
                op = ler.nextInt();

                switch (op){

                    case 1:

                        String logradouro;
                        int numero;
                        String complemento;
                        String bairro;
                        String cidade;
                        String estado;
                        String CEP;

                        System.out.println("Digite o logradouro: ");
                        logradouro = ler.next();
                        System.out.println("Digite o numero: ");
                        numero = ler.nextInt();
                        System.out.println("Digite o complemento: ");
                        complemento = ler.next();
                        System.out.println("Digite o bairro: ");
                        bairro = ler.next();
                        System.out.println("Digite a cidade: ");
                        cidade = ler.next();
                        System.out.println("Digite o estado: ");
                        estado = ler.next();
                        System.out.println("Digite o CEP: ");
                        CEP = ler.next();
                        Agenda.get(CadastroPessoa).adicionaEndereco(logradouro,numero,complemento,bairro,cidade,
                                                                    estado,CEP);

                        break;
                    case 2:

                        Agenda.get(CadastroPessoa).removeEndereco(interage.ObtemID(CadastroPessoa,Agenda));

                        break;
                    case 0:

                        System.out.println("\nTchauzinho :3");

                        break;
                    default:

                        System.out.println("Essa opção não existe!");

                        break;
                }

                break;

            case 0:

                System.out.println("\nTchauzinho :3");

                break;

            default:

                System.out.println("Essa opção não existe!");

                break;
        }

    }

    public void Imprimr(Map<String,Registro> Agenda){

        for (String i : Agenda.keySet()){

            System.out.println("Nome: " + Agenda.get(i).getNome());
            System.out.println("Pessoa: " + Agenda.get(i).getPessoa());
            interage.ImprimeTelefone(Agenda.get(i).getPessoa(),Agenda);
            interage.ImprimeEnderecos(Agenda.get(i).getPessoa(),Agenda);
        }

    }
}
