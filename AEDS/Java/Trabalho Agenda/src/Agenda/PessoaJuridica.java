package Agenda;

public class PessoaJuridica extends Pessoa {

    private static final String validacao = "^[0-9]{3}\\.?[0-9]{3}\\.?[0-9]{3}\\-?[0-9]{2}|[0-9]{2}\\.?[0-9]{3}\\.?[0-9]{3}\\/?[0-9]{4}\\-?[0-9]{2}$";

    public PessoaJuridica(String numero){

        if (ValidaCNPJ(numero) == true) this.CadastroPessoa = numero;

    }

    private boolean ValidaCNPJ(String numero) throws IllegalArgumentException{

        if (!numero.matches(validacao)){

            throw new IllegalArgumentException("Not a valid CNPJ format");
        }

        return true;
    }

    @Override
    public void setNumero(String CadastroPessoa) { this.CadastroPessoa = CadastroPessoa; }
}
