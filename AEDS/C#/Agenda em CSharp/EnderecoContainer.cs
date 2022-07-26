using System;
using System.Collections.Generic;
using System.Text;

namespace Agenda_em_CSharp
{
    class EnderecoContainer
    {

        public int id;
        public string logradouro;
        public int numero;
        public string complemento;
        public string bairro;
        public string cidade;
        public string estado;
        public string CEP;

        public EnderecoContainer(string Logradouro, int Numero, string Complemento, string Bairro,
                        string Cidade, string Estado, string CEP, int ID){

            this.logradouro = Logradouro;
            this.numero = Numero;
            this.complemento = Complemento;
            this.bairro = Bairro;
            this.cidade = Cidade;
            this.estado = Estado;
            this.CEP = CEP;
            this.id = ID;
        }
    }
}
