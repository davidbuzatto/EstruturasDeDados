/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package algoritmosbuscaordenacaografico.gui;

import algoritmosbuscaordenacaografico.sorters.Elemento;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import javax.swing.JPanel;

/**
 *
 * @author David
 */
public class DrawPanel extends JPanel {

    private Elemento[] elementos;
    private Color corNormal;
    private Color corAtivo;
    private Color corPivoOuEleito;
    
    @Override
    protected void paintComponent( Graphics g ) {
        
        super.paintComponent( g );
        Graphics2D g2d = ( Graphics2D ) g.create();
        
        int cont = 0;
        int larguraGrafico = 4;
        int alturaSecaoGrafico = 5;
        int espacamentoGrafico = 3;
            
        g2d.setColor( Color.WHITE );
        g2d.fillRect( 0, 0, getWidth(), getWidth() );

        if ( elementos != null ) {
            
            for ( Elemento v : elementos ) {

                if ( v.ativo ) {
                    g2d.setColor( corAtivo );
                } 
                
                if ( v.pivoOuEleito ) {
                    g2d.setColor( corPivoOuEleito );
                }
                
                if ( !v.pivoOuEleito && !v.ativo ) {
                    g2d.setColor( corNormal );
                }

                g2d.fillRect( 
                        cont * larguraGrafico + ( cont * espacamentoGrafico ), 
                        getHeight() - ( v.valor * alturaSecaoGrafico ), 
                        larguraGrafico, v.valor * alturaSecaoGrafico );

                cont++;

            }
            
        }
    
        g2d.dispose();
        
    }

    public void setCorAtivo( Color corAtivo ) {
        this.corAtivo = corAtivo;
    }

    public void setCorNormal( Color corNormal ) {
        this.corNormal = corNormal;
    }

    public void setCorPivoOuEleito( Color corPivoOuEleito ) {
        this.corPivoOuEleito = corPivoOuEleito;
    }

    public void setElementos( Elemento[] elementos ) {
        this.elementos = elementos;
    }
    
}
