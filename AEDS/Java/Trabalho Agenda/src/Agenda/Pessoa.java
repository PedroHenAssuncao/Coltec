package Agenda;

public abstract class Pessoa {

    protected String CadastroPessoa;

    public String getNumero() {return this.CadastroPessoa; }

    public abstract void setNumero(String CadastroPessoa);
}
