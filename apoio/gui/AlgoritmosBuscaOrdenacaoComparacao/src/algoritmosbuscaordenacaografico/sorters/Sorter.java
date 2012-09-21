/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package algoritmosbuscaordenacaografico.sorters;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author David Buzatto
 */
public abstract class Sorter {

    private List<Elemento[]> lista;
    
    public Sorter() {
        lista = new ArrayList<Elemento[]>();
    }
    
    // insere um array no DrawEngine, clonando o array passado
    protected void addArray( int[] array, Comparacao... comparacoes ) {
        
        Elemento[] es = new Elemento[array.length];
        
        for ( int i = 0; i < array.length; i++ ) {
            
            es[i] = new Elemento( array[i], false, false );
            
            
            for ( Comparacao c : comparacoes ) {
                
                if ( c != null ) {
                    if ( c.tipo == Comparacao.Tipo.INDICE ) {
                        if ( c.valor == i ) {
                            es[i].ativo = true;
                        }
                    } else if ( c.tipo == Comparacao.Tipo.PIVO_OU_ELEITO ) {
                        if ( c.valor == i ) {
                            es[i].pivoOuEleito = true;
                        }
                    } else {
                        if ( c.valor == array[i] ) {
                            es[i].ativo = true;
                        }
                    }
                }
                
            }
            
        }
        
        lista.add( es );
        
    }
    
    public void clear() {
        lista.clear();
    }

    public List<Elemento[]> getLista() {
        return lista;
    }

    public abstract void sortIt( int[] array );

}
