using System;
using System.Collections.Generic;
using System.Text;
using System.Text.RegularExpressions;

namespace Agenda_em_CSharp
{
    class PessoaJuridica : Pessoa
    {

        private static readonly string validador = "^[0-9]{2}\\.?[0-9]{3}\\.?[0-9]{3}\\/?[0-9]{4}\\-?[0-9]{2}$";

        public PessoaJuridica(string numero){

            if (ValidaCNPJ(numero)) this.numero = numero;

            else throw new ArgumentException("Invalid Format");
        }

        private bool ValidaCNPJ(string numero){

            if (Regex.IsMatch(numero, validador)) return true;

            else return false;
        }
        public override void SetNumero(string numero){

            if (ValidaCNPJ(numero)) this.numero = numero;

            else throw new ArgumentException("Invalid CNPJ");
        }
    }
}
