using System;
using System.Collections.Generic;
namespace Agenda_em_CSharp
{
    class Registro
    {

        private Pessoa pessoa;
        private string Nome;
        private List<Telefone> telefones = new List<Telefone>();
        private List<Endereco> enderecos = new List<Endereco>();

        public string GetNumeroDeIdentificacao() { return this.pessoa.GetNumero(); }

        public string GetNome() { return this.Nome; }

        public void SetNome(string nome) { this.Nome = nome; }

        public void AdicionaTelefone( string Telefone){

            Telefone novoItem = new Telefone(Telefone);
            this.telefones.Add(novoItem);

        }

        public void RemoveTelefone( string Telefone) {

            bool ObjRemovido = false;

            foreach (Telefone i in this.telefones){

                if (i.Equals(Telefone)){
                    telefones.Remove(i);
                    ObjRemovido = !ObjRemovido;
                    break;
                }
            }

            if (ObjRemovido == false) Console.WriteLine("Item não encontrado");
        }

        public string[] ObtemNumeros(){

            string[] retorno = new string[this.telefones.Count];

            int i = 0;

            foreach(Telefone j in this.telefones){

                retorno[i] = j.getTelefone();
                i++;
            }

            return retorno;
        }

        public void AdicionaEndereço(String logradouro, int numero, String complemento,
                                 String bairro, String cidade, String estado, String CEP) {

            Endereco novoItem = new Endereco(logradouro, numero, complemento, bairro,
                                             cidade, estado, CEP);

            this.enderecos.Add(novoItem);
        }

        public void RemoveEndereco(int ID) {

            bool ObjRemovido = false;

            foreach( Endereco i in enderecos){

                if (i.GetId().Equals(ID)){

                    this.enderecos.Remove(i);
                    ObjRemovido = true;
                    break;
                }
            }

            if (ObjRemovido == false) Console.WriteLine(" Item não encontrado");
        }

        public EnderecoContainer[] ObtemEndereco(){

            EnderecoContainer[] retorno = new EnderecoContainer[this.enderecos.Count];

        }
    }
}
