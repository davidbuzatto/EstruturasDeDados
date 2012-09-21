/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package fractais;

import java.awt.BorderLayout;
import javax.swing.JFrame;
import javax.swing.JSlider;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

/**
 *
 * @author David Buzatto
 */
public class JanelaPrincipal extends JFrame {
    
    private PainelTrianguloSierpinski painelDesenho;
    
    public JanelaPrincipal() {
        
        setTitle( "Fractais - Triângulo de Sierpinski" );
        setSize( 500, 500 );
        setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
        
        painelDesenho = new PainelTrianguloSierpinski();
        
        JSlider slider = new JSlider();
        slider.setMinimum( 0 );
        slider.setMaximum( 10 );
        slider.setValue( 0 );
        slider.setPaintTrack( true );
        slider.setPaintTicks( true );
        slider.setPaintLabels( true );
        slider.setSnapToTicks( true );
        slider.setMajorTickSpacing( 1 );
        slider.setMinorTickSpacing( 1 );
        slider.addChangeListener( new ChangeListener() {

            @Override
            public void stateChanged( ChangeEvent e ) {
                painelDesenho.setOrdem( ( (JSlider) e.getSource() ).getValue() );
                painelDesenho.repaint();
            }
            
        });
        
        add( painelDesenho, BorderLayout.CENTER );
        add( slider, BorderLayout.SOUTH );
        
    }
    
}
