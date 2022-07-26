using System;
using System.Collections.Generic;
using System.Text;
using System.Text.RegularExpressions;

namespace Agenda_em_CSharp
{
    class PessoaFisica : Pessoa{

        private static readonly string validador = "^[0-9]{3}\\.?[0-9]{3}\\.?[0-9]{3}\\-?[0-9]{2}$";

        public PessoaFisica(string numero)
        {
            if (ValidaCPF(numero)) this.numero = numero;

            else throw new ArgumentException("Invalid format");
        }

        private bool ValidaCPF(string numero)
        {

            if (Regex.IsMatch(numero, validador)) return true;

            else return false;

        }
        public override void SetNumero(string numero) {

            if (ValidaCPF(numero)) this.numero = numero;

            else throw new ArgumentException("Invalid CPF");
        }
    }
}
