package Agenda;

public class Telefone {

    private String numero;
    private static final String Validacao = "^1\\d\\d(\\d\\d)?$|^0800 ?\\d{3} ?\\d{4}$|^(\\(0?([1-9a-zA-Z][0-9a-zA-Z])?[1-9]\\d\\) ?|0?([1-9a-zA-Z][0-9a-zA-Z])?[1-9]\\d[ .-]?)?(9|9[ .-])?[2-9]\\d{3}[ .-]?\\d{4}$";

    public Telefone(String numero){

        this.numero = ValidaNumero(numero);
    }

    public String getNumero(){ return this.numero; }

    public void setNumero(String numero) {

        this.numero = ValidaNumero(numero);

    }

    private String ValidaNumero(String numero) throws IllegalArgumentException{

        if (!numero.matches(Validacao)) {
            throw new IllegalArgumentException("Not a valid phone format");
        }

        String str = numero.replaceAll("[^\\d]", "");

        if (str.c(0) == '0') {
            if (str.charAt(1) == '0') {
                str = str.substring(2);
            } else {
                str = str.substring(1);
            }
        }

        switch (str.length()) {
            case 8:
                return applyMask(str, "AAAA-AAAA", 'A');
            case 9:
                return applyMask(str, "AAAAA-AAAA", 'A');
            case 10:
                return applyMask(str, "(AA) AAAA-AAAA", 'A');
            case 11:
                return applyMask(str, "(AA) AAAAA-AAAA", 'A');
            default:
                return str;
        }
    }

    private String applyMask(String str, String mask, char specialChar) {

        // Conta quantos caracteres especiais existem na máscara
        int maskChCount = mask.length() - mask.replaceAll("[^" + specialChar + "]", "").length();

        // Conta apenas os números
        int strChCount = str.length() - str.replaceAll("\\d", "").length();

        // Exceção caso a string nao tenha números suficientes para competar a máscara
        if (strChCount < maskChCount) {
            throw new IllegalArgumentException("The number of chars in the string should not be smaller than the " +
                    "number of special chars in the mask");
        }

        char[] maskChars = mask.toCharArray();
        char[] strChars = str.toCharArray();

        // Itera por todos os elementos da máscara
        for (int i = 0, j = 0; i < maskChars.length && j < strChars.length; i++) {
            char ch = maskChars[i];
            char sh = strChars[j];

            if (ch == specialChar) {
                // Se achou o caractere especial, buscar o próximo elemento aceito da String e
                // substituí-lo no local do caractere especial
                while (!Character.toString(sh).matches("\\d")) {
                    j++;
                    sh = strChars[j];
                }
                maskChars[i] = sh;
                j++;
            }
        }

        return new String(maskChars);
    }

}
