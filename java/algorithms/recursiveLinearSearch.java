import java.util.Arrays;

public class recursiveLinearSearch{


	public static void main(String... args){
		int[] data = {5, 6, 7, 1, 1, 15};
		recursiveLinearSearch(data, 9);
		recursiveLinearSearch(data, 1);

	}

	/**
     *      Metodo recursivo que faz uma busca linear em um arranjo para encontrar uma chave
     * @param data  Arranjo para ser pesquisado.
     * @param searchKey Chave a ser encontrada.
     * @return Se encontrar a chave de pesquisa dentro do array
     * retorna o indice aonde se encontra o elemento, caso contrario, retorna -1
     */
    public static int recursiveLinearSearch(int data[], int searchKey) {
        assert data != null : "The list can not be null";

        if (data.length == 0)return -1;

        if (searchKey == data[data.length-1]) {
            System.out.println("Found key!, your index is: " + (data.length-1));
            return data.length-1;
        } else {
            return recursiveLinearSearch(Arrays.copyOfRange(data, 0, data.length - 1), searchKey);
        }
	}	

}