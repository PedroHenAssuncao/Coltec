package Agenda;

import java.util.ArrayList;
import java.util.List;

public class Registro {

    private Pessoa pessoa;
    private String nome;
    private List<Telefone> telefone = new ArrayList<Telefone>();
    private List<Endereco> enderecos = new ArrayList<Endereco>();

    public String getNumeroIdentificacao() { return this.pessoa.CadastroPessoa; }

    public String getNome() { return this.nome; }

    public String getPessoa() { return this.pessoa.getNumero(); }

    public void setPessoa(Pessoa pessoa) { this.pessoa = pessoa; }

    public void setNome(String nome) { this.nome = nome; }

    public void adicionaTelefone(String telefone){

        Telefone novoitem = new Telefone(telefone);
        this.telefone.add(novoitem);
    }

    public void removeTelefone(String telefone){

        Telefone comparador = new Telefone(telefone);

        for (Telefone i : this.telefone){

            if (i.getNumero().equals(comparador.getNumero())){

                this.telefone.remove(comparador);
                break;
            }
        }


    }

    public String[] obtemTelefones(){

        String[] retorna = new String[this.telefone.size()];

        for (int i = 0; i < this.telefone.size(); i++){

            retorna[i] = this.telefone.get(i).getNumero();

        }

        return retorna;
    }

    public void adicionaEndereco(String logradouro, int numero, String complemento,
                                 String bairro, String cidade, String estado, String CEP){

        Endereco novoItem = new Endereco(logradouro,numero,complemento,bairro,
                                         cidade,estado,CEP);

        this.enderecos.add(novoItem);
    }

    public void removeEndereco(int ID){

        for (Endereco i : this.enderecos){

            if (i.getId() == ID){

                this.enderecos.remove(i);
                break;
            }
        }
    }

    public EnderecoContainer[] obtemEnderecos(){

        EnderecoContainer[] retorno = new EnderecoContainer[this.enderecos.size()];

        for (int i = 0; i < this.enderecos.size(); i++) {

            retorno[i] = new EnderecoContainer(this.enderecos.get(i).getId(),
                    this.enderecos.get(i).getLogradouro(),this.enderecos.get(i).getNumero(),
                    this.enderecos.get(i).getComplemento(),this.enderecos.get(i).getBairro(),
                    this.enderecos.get(i).getCidade(),this.enderecos.get(i).getEstado(),
                    this.enderecos.get(i).getCEP());
        }

        return retorno;
    }

    public void Imprimir(){

        System.out.println("Nome: " + this.nome);
        System.out.println("CPF/CNPJ: " + this.pessoa.getNumero());
        System.out.println("\t----Telefones-----");
        for (Telefone i : this.telefone){
            System.out.println(i.getNumero());
        }
        System.out.println("\t----Endereços-----");
        for (Endereco i : this.enderecos){

            System.out.println("Id: " + i.getId());
            System.out.println("Logradouro: " + i.getLogradouro());
            System.out.println("Numero: " + i.getNumero());
            System.out.println("Complemento: " + i.getComplemento());
            System.out.println("Bairro: " + i.getBairro());
            System.out.println("Cidade: " + i.getCidade());
            System.out.println("Estado: " + i.getEstado());
            System.out.println("CEP: " + i.getCEP());
            System.out.println();
        }
    }
}
