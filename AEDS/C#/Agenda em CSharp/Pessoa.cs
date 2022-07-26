using System;
using System.Collections.Generic;
using System.Text;

namespace Agenda_em_CSharp
{
    abstract class Pessoa{

        protected string numero;

        public string GetNumero() { return this.numero; }

        public abstract void SetNumero(string numero);
    }
}
