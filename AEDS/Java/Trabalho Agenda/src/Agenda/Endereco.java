package Agenda;

public class Endereco {

    private int id;
    private String logradouro;
    private int numero;
    private String complemento;
    private String bairro;
    private String cidade;
    private String estado;
    private String CEP;
    private static int Contador = 0;

    public Endereco(String logradouro, int numero, String complemento, String bairro,
                    String cidade, String estado, String CEP){

        this.logradouro = logradouro;
        this.numero = numero;
        this.complemento = complemento;
        this.bairro = bairro;
        this.cidade = cidade;
        this.estado = estado;
        this.CEP = CEP;
        this.id = Endereco.Contador;
        Endereco.Contador++;

    }

    // Metodos get

    public int getId(){ return this.id; }

    public String getLogradouro(){ return this.logradouro; }

    public int getNumero(){ return this.numero; }

    public String getComplemento(){ return this.complemento; }

    public String getBairro(){ return this.bairro; }

    public String getCidade(){ return  this.cidade; }

    public String getEstado(){ return this.estado; }

    public String getCEP(){ return this.CEP; }

    // Metodos set

    public void setLogradouro(String logradouro) { this.logradouro = logradouro; }

    public void setNumero(int numero) { this.numero = numero; }

    public void setComplemento(String complemento) { this.complemento = complemento; }

    public void setBairro(String bairro) { this.bairro = bairro; }

    public void setCidade(String cidade) { this.cidade = cidade; }

    public void setEstado(String estado) { this.estado = estado; }

    public void setCEP(String CEP) { this.CEP = CEP; }
}
