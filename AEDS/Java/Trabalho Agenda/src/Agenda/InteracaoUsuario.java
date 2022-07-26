package Agenda;

import java.util.Map;
import java.util.Scanner;

public class InteracaoUsuario {

    public String ObtemNome(){

        Scanner ler = new Scanner(System.in);
        String nome;

        System.out.println("Digite o nome do contato: ");
        nome = ler.next();

        return nome;
    }

    public String ObtemNumero(){

        Scanner ler = new Scanner(System.in);
        String numero;

        System.out.println("Digite o CPF/CNPJ da pessoa: ");
        numero = ler.next();

        return numero;
    }

    public String ObtemTelefone(){

        Scanner ler = new Scanner(System.in);
        String telefone;

        System.out.println("Digite o numero de telefone do contato: ");
        telefone = ler.next();

        return telefone;
    }

    public int ObtemID(String CadastroPessoa, Map<String,Registro> Agenda){

        EnderecoContainer[] temp = Agenda.get(CadastroPessoa).obtemEnderecos().clone();

        for (EnderecoContainer i : temp){

            System.out.println("Id: " + i.id);
            System.out.println("Logradouro: " + i.logradouro);
            System.out.println("Numero: " + i.numero);
            System.out.println("Complemento: " + i.complemento);
            System.out.println("Bairro: " + i.bairro);
            System.out.println("Cidade: " + i.cidade);
            System.out.println("Estado: " + i.estado);
            System.out.println("CEP: " + i.CEP);
        }

        int Id_desejado;
        Scanner ler = new Scanner(System.in);

        System.out.println("\n\tQual desses Ids você deseja?");
        System.out.println("> ");
        Id_desejado = ler.nextInt();

        return Id_desejado;
    }

    public void ImprimeEnderecos(String CadastroPessoa,Map<String,Registro> Agenda){

        EnderecoContainer[] temp = Agenda.get(CadastroPessoa).obtemEnderecos().clone() ;


        for (EnderecoContainer i : temp) {

            System.out.println("Id: " + i.id);
            System.out.println("Logradouro: " + i.logradouro);
            System.out.println("Numero: " + i.numero);
            System.out.println("Complemento: " + i.complemento);
            System.out.println("Bairro: " + i.bairro);
            System.out.println("Cidade: " + i.cidade);
            System.out.println("Estado: " + i.estado);
            System.out.println("CEP: " + i.CEP);
        }
    }

    public void ImprimeTelefone(String CadastroPessoa, Map<String,Registro> Agenda){

        String[] temp = Agenda.get(CadastroPessoa).obtemTelefones().clone();

        for (String i : temp){

            System.out.println(i);
        }
    }
}
