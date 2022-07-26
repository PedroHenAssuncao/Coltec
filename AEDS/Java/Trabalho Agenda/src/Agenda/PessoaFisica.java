package Agenda;

public class PessoaFisica extends Pessoa {

    private static final String validacao = "^[0-9]{3}\\.?[0-9]{3}\\.?[0-9]{3}\\-?[0-9]{2}$";

    public PessoaFisica(String numero) throws IllegalArgumentException{

        if (validaCPF(numero)) this.CadastroPessoa = numero;

        else throw new IllegalArgumentException("Invalid CPF format");
    }

    @Override
    public void setNumero(String CadastroPessoa) { this.CadastroPessoa = CadastroPessoa; }

    private boolean validaCPF(String numero){

        if (!numero.matches(validacao)){

            return false;
        }

        return true;

    }
}
