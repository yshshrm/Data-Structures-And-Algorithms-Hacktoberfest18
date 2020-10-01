abstract class Arvore
class NoArvore(val info:Int,val list:List<Arvore>):Arvore()
//Arvore Ilimitada Exponencial
object Nil:Arvore()

fun inserirElemento(arv:Arvore,elemento:Int,nivel:Int):Arvore= when(arv){
    is NoArvore -> (if(calcularFilhosNivel(arv) < elevarDois(nivel)) {
        val novaLista = adiciona(NoArvore(elemento, List<Arvore>(elevarDois(nivel + 1))), arv.list)
        NoArvore(arv.info,novaLista)

    }
                    else{ val arvNo:Arvore = inserirElemento(calculaMenorFilho(Nil,arv.list),elemento,nivel+1)) }
    else-> Nil
}

fun atualizarLista(arv:Arvore,list: List<Arvore>):List<Arvore> = when(arv){
    list.isEmpty() ->  list
    is NoArvore -> if(arv.info == list[0].info)
    else -> if(arv.info == list[0].info)

}

//Adiciona o elemento arv na ultima posição da lista
fun adiciona(arv:Arvore,lista:List<Arvore>):List<Arvore> = when{
    lista.isEmpty() -> listOf(arv)

        else -> listOf(lista[0]) +  adiciona(arv,lista.drop(0))
}

//Calcula a menor raiz de uma lista de arvores
fun calculaMenorFilho(arv: Arvore,lista : List<Arvore>):Arvore = when{
    lista.isEmpty() -> arv
    else -> (if(calcularFilhosNivel(arv)>calcularFilhosNivel(lista[0]))
            { calculaMenorFilho(lista[0],lista.drop(0)) }
                    else { calculaMenorFilho(arv,lista.drop(0))}
            )
}

fun elevarDois(nivel:Int):Int{
    if(nivel == 0){ return 1 }
    else{ return 2*elevarDois(nivel-1) }
}

fun calcularFilhosNivel(arv:Arvore):Int = when(arv){
    is NoArvore -> (arv.list.size)
    else -> 0
}