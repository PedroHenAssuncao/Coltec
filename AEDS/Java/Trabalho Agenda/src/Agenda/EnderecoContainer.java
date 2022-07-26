package Agenda;

public class EnderecoContainer {

    public int id;
    public String logradouro;
    public int numero;
    public String complemento;
    public String bairro;
    public String cidade;
    public String estado;
    public String CEP;

    public EnderecoContainer(int id, String logradouro, int numero,
                             String complemento, String bairro, String cidade,
                             String estado, String CEP){

        this.id = id;
        this.logradouro = logradouro;
        this.numero = numero;
        this.complemento = complemento;
        this.bairro = bairro;
        this.cidade = cidade;
        this.estado = estado;
        this.CEP = CEP;

    }
}
