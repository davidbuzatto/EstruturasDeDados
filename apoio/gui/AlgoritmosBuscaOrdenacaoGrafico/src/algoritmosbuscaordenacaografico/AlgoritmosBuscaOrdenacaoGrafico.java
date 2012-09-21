/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package algoritmosbuscaordenacaografico;

import algoritmosbuscaordenacaografico.gui.JanelaPrincipal;
import javax.swing.UIManager;
import javax.swing.UIManager.LookAndFeelInfo;
import javax.swing.UnsupportedLookAndFeelException;

/**
 *
 * @author David
 */
public class AlgoritmosBuscaOrdenacaoGrafico {

    /**
     * @param args the command line arguments
     */
    public static void main( String[] args ) {
        
        try {
            for ( LookAndFeelInfo info : UIManager.getInstalledLookAndFeels() ) {
                if ( "Nimbus".equals( info.getName() ) ) {
                    UIManager.setLookAndFeel( info.getClassName() );
                    break;
                }
            }
        } catch ( UnsupportedLookAndFeelException exc ) {
            exc.printStackTrace();
        } catch ( ClassNotFoundException exc ) {
            exc.printStackTrace();
        } catch ( InstantiationException exc ) {
            exc.printStackTrace();
        } catch ( IllegalAccessException exc ) {
            exc.printStackTrace();
        }
        
        java.awt.EventQueue.invokeLater( new Runnable() {
            public void run() {
                new JanelaPrincipal().setVisible( true );
            }
        });
        
    }
}
