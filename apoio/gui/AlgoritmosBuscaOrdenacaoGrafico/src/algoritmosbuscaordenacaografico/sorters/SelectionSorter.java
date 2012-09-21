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
    public void sortIt( Comparable[] array ) {

        cleanEngine();
        Element[] elementos = preprocessArray( array );
        
        addArray( elementos );
        
        int j;
        Element eleito;
        Element menor;
        int posicao;

        for ( int i = 0; i < elementos.length - 1; i++ ) {

            eleito = elementos[i];
            menor = elementos[i+1];
            posicao = i + 1;
            
            for ( j = i+1; j < elementos.length; j++ ) {

                if ( elementos[j].compareTo( menor ) < 0 ) {
                    menor = elementos[j];
                    posicao = j;
                }
                
                //addArray( elementos );

            }

            if ( menor.compareTo( eleito ) < 0 ) {

                Element temp = elementos[i];
                elementos[i] = elementos[posicao];
                elementos[posicao] = temp;
                
                addArray( elementos );

            }

        }

    }
    
    /*@Override
    public void sortIt( Comparable[] array ) {

        cleanEngine();
        Element[] elementos = preprocessArray( array );
        
        addArray( elementos );
        
        for ( int j = elementos.length - 1; j >= 0; j-- ) {
            int m = maxPos( elementos, j );
            Element temp = elementos[m];
            elementos[m] = elementos[j];
            elementos[j] = temp;
            addArray( elementos );
        }

    }

    private int maxPos( Element[] elementos, int ate ) {

        int c = 0;
        Element maximo = elementos[0];

        for ( int i = 0; i <= ate; i++ ) {
            if ( maximo.compareTo( elementos[i] ) < 0 ) {
                maximo = elementos[i];
                c = i;
            }
        }

        return c;
    }*/

}
