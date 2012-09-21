/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package sorters;

import drawEngine.*;
import java.awt.*;

/**
 *
 * @author David Buzatto
 */
public abstract class Sorter {

    private DrawEngine drawEngine;

    public Sorter() {
        drawEngine = new DrawEngine();
    }

    // insere um array no DrawEngine, clonando o array passado
    protected void addArray( Element[] array ) {
        drawEngine.addArray( array.clone() );
    }

    // limpa a lista de arrays da engine
    public void cleanEngine() {
        drawEngine.clean();
    }

    // preprocessa o array, criando elementos usando os itens do array
    public Element[] preprocessArray( Comparable[] array ) {

        Element[] a = new Element[array.length];

        for ( int i = 0; i < array.length; i++ ) {
            a[i] = new Element( i, array[i] );
        }

        return a;

    }

    // manda desenhar
    public void drawIt( Graphics g, boolean drawLabels ) {
        drawEngine.drawIt( g, drawLabels );
    }

    public abstract void sortIt( Comparable[] array );

}
