/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package algoritmosbuscaordenacaografico.gui;

import algoritmosbuscaordenacaografico.sorters.Sorter;
import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JPanel;

/**
 *
 * @author David Buzatto
 */
public class SorterPanel extends JPanel {

    private Sorter sorter;
    private boolean showLabels;

    @Override
    protected void paintComponent( Graphics g ) {
        super.paintComponent( g );

        g.setColor( Color.WHITE );
        g.fillRect( 0, 0, getWidth(), getHeight() );

        if ( sorter != null ) {
            sorter.drawIt( g, showLabels );
        }
    }

    public void setSorter( Sorter sorter ) {
        this.sorter = sorter;
    }

    public boolean isShowLabels() {
        return showLabels;
    }

    public void setShowLabels( boolean showLabels ) {
        this.showLabels = showLabels;
    }

    public Sorter getSorter() {
        return sorter;
    }

}
