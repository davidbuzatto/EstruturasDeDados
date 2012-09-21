/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package arvorebinariabuscagrafico.gui;

import java.awt.*;

/**
 *
 * @author David
 */
public class ArestaGrafico {
    
    public NoGrafico origem;
    public NoGrafico destino;
    
    public ArestaGrafico( NoGrafico origem, NoGrafico destino ) {
        this.origem = origem;
        this.destino = destino;
    }
    
    public void desenhar( Graphics2D g ) {
        
        g.setStroke( new BasicStroke( 2 ) );
        g.setColor( Color.BLACK );
        
        if ( origem != null && destino != null && origem.no != null && destino.no != null ) {
            g.drawLine( origem.centroX, origem.centroY, destino.centroX, destino.centroY );
        }
        
    }
    
}
