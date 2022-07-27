let num = document.getElementById("txt1")
let lista = document.getElementById("flista")
let res = document.getElementById("res")
let valores = []

function isNumero(n){
    if(Number(n) >= 1 && Number(n) <= 100){
        return true
    } else {
        return false
    }
}

function inLista(n, l){
    if(l.indexOf(Number(n)) != -1){
        return true
    }
    else{
        return false
    }

}

function Adiciona(){
    if(isNumero(num.value) && !inLista(num.value, valores)){
      valores.push(Number(num.value))
      let item = document.createElement('option')
      item.text = "Valor " + num.value + " adicionado"
      lista.appendChild(item)
      res.innerHTML = ''
    } else {

        window.alert("Valor inválido ou já encontrado na lista")
    }

    num.value = ''
    num.focus()
}

function Finaliza(){
    if(valores.length == 0){
        window.alert("É necessário adicionar valores antes de finalizar!")
    }
    else{
        
        let total = valores.length
        let maior = valores[0]
        let menor = valores[0]
        let soma = 0
        let media = 0

        for(let i in valores){
            soma += valores[i]
            if(valores[i] > maior){
                maior = valores[i]
            }
            if(valores[i] < menor){
                menor = valores[i]
            }
        }

        media = soma/valores.length

        res.innerHTML = ''
        res.innerHTML += '<p>Ao todo, temos ' + total +' numeros cadastrados</p>'
        res.innerHTML += '<p>O maior valor adicionado foi '+maior+' e o menor foi '+menor+' </p>'
        res.innerHTML += '<p>A soma de todos os valores é '+soma+'</p>'
        res.innerHTML += '<p>A media dos valores é '+media+'</p>'
    }
}