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
    public void sortIt( Comparable[] array ) {

        cleanEngine();
        Element[] elementos = preprocessArray( array );
        
        addArray( elementos );
        
        int j;
        Element eleito;

        for ( int i = 1; i < elementos.length; i++ ) {

            eleito = elementos[i];
            
            for ( j = i-1; j >= 0 && eleito.compareTo( elementos[j] ) < 0; j-- ) {

                elementos[j+1] = elementos[j];

            }

            elementos[j+1] = eleito;
            addArray( elementos );

        }

    }
    
    /*@Override
    public void sortIt( Comparable[] array ) {

        cleanEngine();
        Element[] elementos = preprocessArray( array );

        List<Element> list = asList( elementos );

        for ( int i = 1; i < list.size(); i++ ) {
            for( int j = 0; j < i; j++ ) {
                if ( list.get( i ).compareTo( list.get( j ) ) < 0 ) {
                    Element e = list.remove( i );
                    list.add( j, e );
                    addArray( list.toArray( new Element[0] ) );
                }
            }
        }

    }

    private List<Element> asList( Element[] elementos ) {
        List<Element> lista = new ArrayList<Element>();
        for ( Element e : elementos ) {
            lista.add( e );
        }
        return lista;
    }*/

}
