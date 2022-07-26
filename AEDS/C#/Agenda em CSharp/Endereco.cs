using System;
using System.Collections.Generic;
using System.Text;

namespace Agenda_em_CSharp
{
    class Endereco
    {

        private int id;
        private string logradouro;
        private int numero;
        private string complemento;
        private string bairro;
        private string cidade;
        private string estado;
        private string CEP;
        private static int contador = 0;

        public Endereco(string Logradouro, int Numero, string Complemento, string Bairro,
                        string Cidade, string Estado, string CEP) {

            this.logradouro = Logradouro;
            this.numero = Numero;
            this.complemento = Complemento;
            this.bairro = Bairro;
            this.cidade = Cidade;
            this.estado = Estado;
            this.CEP = CEP;
            this.id = Endereco.contador;
            Endereco.contador++;
        }

        public int GetId() { return this.id; }

        public string GetLogradouro() { return this.logradouro; }

        public int GetNumero() { return this.numero; }

        public string GetComplemento() { return this.complemento; }

        public string GetBairro() { return this.bairro; }

        public string GetCidade() { return this.cidade; }

        public string GetEstado() { return this.estado; }

        public string GetCEP() { return this.CEP; }

        public void SetLogradouro(string Logradouro) { this.logradouro = Logradouro; }

        public void SetNumero(int Numero) { this.numero = Numero; }

        public void SetComplemento(string Complemento) { this.complemento = Complemento; }

        public void SetBairro(string Bairro) { this.bairro = Bairro; }

        public void SetCidade(string Cidade) { this.cidade = Cidade; }

        public void SetEstado(string Estado) { this.estado = Estado; }

        public void SetCEP(string CEP) { this.CEP = CEP; }
    }
}
