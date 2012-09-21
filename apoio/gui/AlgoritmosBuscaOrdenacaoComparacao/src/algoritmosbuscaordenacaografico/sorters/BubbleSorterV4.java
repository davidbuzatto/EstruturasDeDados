/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package algoritmosbuscaordenacaografico.sorters;

/**
 *
 * @author David Buzatto
 */
public class BubbleSorterV4 extends Sorter {

    @Override
    public void sortIt( int[] array ) {

        clear();
        int limite = array.length-1;
        int posicaoUltimaTroca =  0;
        
        addArray( array, null, null );
        
        while ( true ) {
            
            posicaoUltimaTroca  = 0;
            
            for ( int j = 0; j < limite; j++ ) {
                
                addArray( array, 
                        new Comparacao( j, Comparacao.Tipo.INDICE ), 
                        new Comparacao( j+1, Comparacao.Tipo.INDICE ) );
                
                if ( array[j] > array[j+1] ) {
                    int temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                    posicaoUltimaTroca  = j;
                }
                
                addArray( array, null, null );
                
            }
            
            if ( posicaoUltimaTroca  == 0 ) {
                return;
            }
            
            limite = posicaoUltimaTroca ;
            
        }

    }

}
