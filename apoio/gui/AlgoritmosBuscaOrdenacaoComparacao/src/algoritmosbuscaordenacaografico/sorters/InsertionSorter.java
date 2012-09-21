/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package algoritmosbuscaordenacaografico.sorters;

import java.util.*;

/**
 *
 * @author David Buzatto
 */
public class InsertionSorter extends Sorter {
    
    @Override
    public void sortIt( int[] array ) {

        clear();
        addArray( array, null, null );
        
        int j;
        int eleito;

        for ( int i = 1; i < array.length; i++ ) {

            eleito = array[i];
            
            addArray( array, new Comparacao( i, Comparacao.Tipo.PIVO_OU_ELEITO ) );
            
            for ( j = i-1; j >= 0; j-- ) {
                
                addArray( array, 
                        new Comparacao( j, Comparacao.Tipo.INDICE ),
                        new Comparacao( i, Comparacao.Tipo.PIVO_OU_ELEITO ) );
                
                if ( eleito < array[j] ) {
                    
                    addArray( array, 
                            new Comparacao( j, Comparacao.Tipo.INDICE ), 
                            new Comparacao( j+1, Comparacao.Tipo.INDICE ),
                            new Comparacao( i, Comparacao.Tipo.PIVO_OU_ELEITO ) );
                    
                    array[j+1] = array[j];
                    
                    addArray( array, 
                            new Comparacao( j, Comparacao.Tipo.INDICE ), 
                            new Comparacao( j+1, Comparacao.Tipo.INDICE ),
                            new Comparacao( i, Comparacao.Tipo.PIVO_OU_ELEITO ) );
                    
                } else {
                    break;
                }

            }
            
            addArray( array, 
                    new Comparacao( j, Comparacao.Tipo.INDICE ), 
                    new Comparacao( j+1, Comparacao.Tipo.INDICE ),
                    new Comparacao( i, Comparacao.Tipo.PIVO_OU_ELEITO ) );
            
            array[j+1] = eleito;
            
            addArray( array );

        }

    }

}
