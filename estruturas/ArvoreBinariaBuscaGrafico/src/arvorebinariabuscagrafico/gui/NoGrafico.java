/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package arvorebinariabuscagrafico.gui;

import arvorebinariabuscagrafico.arvorebinaria.No;
import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Graphics2D;
import java.util.Objects;

/**
 *
 * @author David
 */
public class NoGrafico {
    
    // membros públicos de novo! não faça isso! que coisa feia...
    public No no;
    public int centroX;
    public int centroY;
    public int nivel;
    public boolean visitado;
    
    public static final int DIAMETRO = 50;
    
    public NoGrafico( No no, int centroX, int centroY, int nivel ) {
        this.no = no;
        this.centroX = centroX;
        this.centroY = centroY;
        this.nivel = nivel;
    }
    
    public void desenhar( Graphics2D g, 
            boolean mostrarNivel, 
            boolean mostrarGrau,
            boolean mostrarOrdem ) {
        
        g.setStroke( new BasicStroke( 2 ) );
        
        if ( visitado ) {
            
            g.setColor( new Color( 104, 153, 211 ) );
            g.fillOval( 
                    centroX - DIAMETRO / 2, 
                    centroY - DIAMETRO / 2, 
                    DIAMETRO, DIAMETRO );
            
            if ( mostrarOrdem ) {
                
                g.setColor( new Color( 14, 83, 167 ) );
                g.setFont( new Font( "Arial", Font.BOLD, 16 ) );
                g.drawString( "o: " + String.valueOf( no.ordemVisita ), 
                        centroX + 5 + DIAMETRO / 2, centroY + 20 );

            }
            
        } else {
            
            g.setColor( Color.WHITE );
            g.fillOval( 
                    centroX - DIAMETRO / 2, 
                    centroY - DIAMETRO / 2, 
                    DIAMETRO, DIAMETRO );
            
        }
        
        
        g.setColor( Color.BLACK );
        g.drawOval( 
                centroX - DIAMETRO / 2, 
                centroY - DIAMETRO / 2, 
                DIAMETRO, DIAMETRO );
        
        g.setFont( new Font( "Arial", Font.BOLD, 25 ) );
        
        FontMetrics fm = g.getFontMetrics();
        String valor = String.valueOf( no.valor );
        int largValor = fm.stringWidth( valor );
        
        g.drawString( valor, centroX - largValor / 2, centroY + 9 );
        
        g.setFont( new Font( "Arial", Font.BOLD, 16 ) );
        
        if ( mostrarNivel ) {
            
            g.setColor( Color.BLACK );
            g.drawString( "n: " + String.valueOf( nivel ), 
                    centroX + 5 + DIAMETRO / 2, centroY - 10 );
            
        }
        
        if ( mostrarGrau ) {
            
            g.setColor( new Color( 0, 118, 51 ) );
            g.drawString( "g: " + String.valueOf( no.grau ), 
                    centroX + 5 + DIAMETRO / 2, centroY + 5 );
            
        }
        
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final NoGrafico other = (NoGrafico) obj;
        if (!Objects.equals(this.no, other.no)) {
            return false;
        }
        return true;
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 97 * hash + Objects.hashCode(this.no);
        return hash;
    }

    @Override
    public String toString() {
        return "NoGrafico{" + "no=" + no + ", centroX=" + centroX + ", centroY=" + centroY + ", nivel=" + nivel + ", visitado=" + visitado + '}';
    }
    
}
