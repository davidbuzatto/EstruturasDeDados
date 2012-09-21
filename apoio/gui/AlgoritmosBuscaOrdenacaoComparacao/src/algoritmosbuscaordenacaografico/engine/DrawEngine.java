/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package algoritmosbuscaordenacaografico.engine;

import algoritmosbuscaordenacaografico.gui.DrawPanel;
import algoritmosbuscaordenacaografico.sorters.Elemento;
import java.util.*;


/**
 *
 * @author David Buzatto
 */
public class DrawEngine implements Runnable {

    private List<Elemento[]> lista;
    private DrawPanel painel;
    private int tempo;
    
    public DrawEngine( List<Elemento[]> lista, DrawPanel painel, int tempo ) {
        this.lista = lista;
        this.painel = painel;
        this.tempo = tempo;
    }

    @Override
    public void run() {
        
        for ( int i = 0; i < lista.size(); i++ ) {
            
            painel.setElementos( lista.get( i ) );
            painel.repaint();
            
            try {
                Thread.sleep( tempo );
            } catch ( InterruptedException exc ) {
            }
            
        }
        
    }
    
}
