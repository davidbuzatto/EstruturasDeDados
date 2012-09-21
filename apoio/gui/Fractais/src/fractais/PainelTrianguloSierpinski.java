/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package fractais;

import java.awt.*;
import java.awt.geom.GeneralPath;
import javax.swing.JPanel;

/**
 *
 * @author David Buzatto
 */
public class PainelTrianguloSierpinski extends JPanel {
    
    private int ordem;
    
    @Override
    protected void paintComponent( Graphics g ) {
        
        super.paintComponent( g );
        
        Graphics2D g2d = ( Graphics2D ) g;
        g2d.setRenderingHint( RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON );
        
        draw( g2d, ordem, 50, 310, 200, 50, 350, 310 );
        
    }
    
    private void draw( Graphics2D g2d, int ordem,
            double x1, double y1, 
            double x2, double y2, 
            double x3, double y3 ) {
        
        if ( ordem == 0 ) {
            
            GeneralPath gp = new GeneralPath();
            gp.moveTo( x1, y1 );
            gp.lineTo( x2, y2 );
            gp.lineTo( x3, y3 );
            gp.closePath();
            
            g2d.fill( gp );
            
        } else {
            
            double tx1 = x1;
            double ty1 = y1;
            double tx3 = x1 + ( ( x3 - x1 ) / 2 );
            double ty3 = y3;
            double tx2 = x1 + ( tx3 - tx1 ) / 2;
            double ty2 = y2 + ( ( y1 - y2 ) / 2 );
            draw( g2d, ordem-1, tx1, ty1, tx2, ty2, tx3, ty3 );
            
            tx1 = tx2;
            ty1 = ty2;
            tx3 = tx3 + (x3 - tx3) / 2;
            ty3 = ty2;
            tx2 = x2;
            ty2 = y2;
            draw( g2d, ordem-1, tx1, ty1, tx2, ty2, tx3, ty3 );
            
            tx1 = x1 + ( ( x3 - x1 ) / 2 );
            ty1 = y3;
            tx2 = tx3;
            ty2 = ty3;
            tx3 = x3;
            ty3 = y3;
            draw( g2d, ordem-1, tx1, ty1, tx2, ty2, tx3, ty3 );
            
        }
        
    }

    public void setOrdem( int ordem ) {
        this.ordem = ordem;
    }
    
}
