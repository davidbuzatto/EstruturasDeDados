/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package algoritmosbuscaordenacaografico.sorters;

/**
 *
 * @author David Buzatto
 */
public class SelectionSorter extends Sorter {
    
    @Override
    public void sortIt( int[] array ) {

        clear();
        addArray( array, null, null );
        
        int j;
        int eleito;
        int menor;
        int posicao;

        for ( int i = 0; i < array.length - 1; i++ ) {

            eleito = array[i];
            menor = array[i+1];
            posicao = i + 1;
            
            for ( j = i+1; j < array.length; j++ ) {
                
                addArray( array, 
                        new Comparacao( j, Comparacao.Tipo.INDICE ), 
                        new Comparacao( posicao, Comparacao.Tipo.INDICE ),
                        new Comparacao( i, Comparacao.Tipo.PIVO_OU_ELEITO ) );
                
                if ( array[j] < menor ) {
                    menor = array[j];
                    posicao = j;
                }
                
                addArray( array, new Comparacao( i, Comparacao.Tipo.PIVO_OU_ELEITO ) );

            }
            
            addArray( array, 
                    new Comparacao( menor, Comparacao.Tipo.VALOR ), 
                    new Comparacao( eleito, Comparacao.Tipo.VALOR ),
                    new Comparacao( i, Comparacao.Tipo.PIVO_OU_ELEITO ) );
            
            if ( menor < eleito ) {

                int temp = array[i];
                array[i] = array[posicao];
                array[posicao] = temp;

            }
            
            addArray( array );

        }

    }

}
