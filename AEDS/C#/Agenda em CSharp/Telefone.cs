using System;
using System.Collections.Generic;
using System.Collections;
using System.Text.RegularExpressions;
using System.Text;

namespace Agenda_em_CSharp
{
    class Telefone{

        private string numero;
        private static readonly string validacao = "^1\\d\\d(\\d\\d)?$|^0800 ?\\d{3} ?\\d{4}$|^(\\(0?([1-9a-zA-Z][0-9a-zA-Z])?[1-9]\\d\\) ?|0?([1-9a-zA-Z][0-9a-zA-Z])?[1-9]\\d[ .-]?)?(9|9[ .-])?[2-9]\\d{3}[ .-]?\\d{4}$";

        public Telefone(string numero){

            this.numero = ValidaNumero(numero);
        }

        public string getTelefone() { return this.numero; }

        public void setTelefone(string novoNumero) { this.numero = novoNumero; }

       private String ValidaNumero(String numero){

        if (!Regex.IsMatch(numero,validacao)){
            throw new ArgumentException("Not a valid phone format");
        }

        String str = numero.Replace("[^\\d]", "");

        if (str[0] == '0') {
            if (str[1] == '0') {
                str = str.Substring(2);
            } else {
                str = str.Substring(1);
            }
        }

        switch (str.Length) {
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
        int maskChCount = mask.Length - mask.Replace("[^" + specialChar + "]", "").Length;

        // Conta apenas os números
        int strChCount = str.Length - str.Replace("\\d", "").Length;

        // Exceção caso a string nao tenha números suficientes para competar a máscara
        if (strChCount < maskChCount) {
            throw new ArgumentException("The number of chars in the string should not be smaller than the " +
                    "number of special chars in the mask");
        }

        char[] maskChars = mask.ToCharArray();
        char[] strChars = str.ToCharArray();

        // Itera por todos os elementos da máscara
        for (int i = 0, j = 0; i < maskChars.Length && j < strChars.Length; i++) {
            char ch = maskChars[i];
            char sh = strChars[j];

            if (ch == specialChar) {
                    // Se achou o caractere especial, buscar o próximo elemento aceito da String e
                    // substituí-lo no local do caractere especial
                    while (!Regex.IsMatch(char.ToString(sh), ("\\d")))
                    {
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
}
