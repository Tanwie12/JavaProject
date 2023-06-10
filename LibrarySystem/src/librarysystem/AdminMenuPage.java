/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package librarysystem;

/**
 *
 * @author Enzo Maria
 */
public class AdminMenuPage extends javax.swing.JFrame {

    /**
     * Creates new form LibrarianDashboard
     */
    public AdminMenuPage() {
        initComponents();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        jLabel1 = new javax.swing.JLabel();
        jSeparator1 = new javax.swing.JSeparator();
        ampnewbooks = new javax.swing.JButton();
        ampavailablebooks = new javax.swing.JButton();
        amplandedbooks = new javax.swing.JButton();
        ampstudentsowing = new javax.swing.JButton();
        ampwaiting = new javax.swing.JButton();
        ampdeletebooks = new javax.swing.JButton();
        amplogout = new javax.swing.JButton();
        amplevy = new javax.swing.JButton();
        ampdismiss = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jPanel1.setBackground(new java.awt.Color(0, 212, 255));

        jLabel1.setFont(new java.awt.Font("Calibri", 1, 36)); // NOI18N
        jLabel1.setText("ADMIN");

        jSeparator1.setForeground(new java.awt.Color(0, 0, 0));

        ampnewbooks.setText("Add New Books");
        ampnewbooks.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ampnewbooksActionPerformed(evt);
            }
        });

        ampavailablebooks.setText("View Available Books");
        ampavailablebooks.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ampavailablebooksActionPerformed(evt);
            }
        });

        amplandedbooks.setText("View Lended Books");
        amplandedbooks.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                amplandedbooksActionPerformed(evt);
            }
        });

        ampstudentsowing.setText("View Students Owing Books");
        ampstudentsowing.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ampstudentsowingActionPerformed(evt);
            }
        });

        ampwaiting.setText("View Waiting Queue");
        ampwaiting.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ampwaitingActionPerformed(evt);
            }
        });

        ampdeletebooks.setText("Delete Books");
        ampdeletebooks.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ampdeletebooksActionPerformed(evt);
            }
        });

        amplogout.setText("Logout");
        amplogout.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                amplogoutActionPerformed(evt);
            }
        });

        amplevy.setText("Levy Students");
        amplevy.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                amplevyActionPerformed(evt);
            }
        });

        ampdismiss.setText("Dismiss Student");
        ampdismiss.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ampdismissActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jSeparator1)
                .addContainerGap())
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(317, 317, 317)
                .addComponent(jLabel1)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(amplogout)
                .addGap(17, 17, 17))
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                .addGap(208, 208, 208)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(ampdismiss, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(amplevy, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(ampdeletebooks, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(ampstudentsowing, javax.swing.GroupLayout.DEFAULT_SIZE, 351, Short.MAX_VALUE)
                    .addComponent(ampnewbooks, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(ampavailablebooks, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(amplandedbooks, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(ampwaiting, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addGap(190, 190, 190))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(30, 30, 30)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jLabel1)
                    .addComponent(amplogout))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jSeparator1, javax.swing.GroupLayout.PREFERRED_SIZE, 10, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(ampnewbooks)
                .addGap(18, 18, 18)
                .addComponent(ampavailablebooks)
                .addGap(18, 18, 18)
                .addComponent(amplandedbooks)
                .addGap(18, 18, 18)
                .addComponent(ampstudentsowing)
                .addGap(18, 18, 18)
                .addComponent(ampwaiting)
                .addGap(18, 18, 18)
                .addComponent(ampdeletebooks)
                .addGap(18, 18, 18)
                .addComponent(amplevy)
                .addGap(18, 18, 18)
                .addComponent(ampdismiss)
                .addContainerGap(65, Short.MAX_VALUE))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void ampstudentsowingActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ampstudentsowingActionPerformed
        // TODO add your handling code here:
        setVisible(false);
        StudentsOwingBooks menu = new StudentsOwingBooks();
        menu.setVisible(true);
    }//GEN-LAST:event_ampstudentsowingActionPerformed

    private void amplevyActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_amplevyActionPerformed
        // TODO add your handling code here:
        setVisible(false);
        LevyStudentsPage menu=new LevyStudentsPage();
        menu.setVisible(true);
    }//GEN-LAST:event_amplevyActionPerformed

    private void amplogoutActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_amplogoutActionPerformed
        // TODO add your handling code here:
        setVisible(false);
        LoginPage logout=new LoginPage();
        logout.setVisible(true);
    }//GEN-LAST:event_amplogoutActionPerformed

    private void ampavailablebooksActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ampavailablebooksActionPerformed
        // TODO add your handling code here:
        setVisible(false);
        AvailableBooksPage menu = new AvailableBooksPage();
        menu.setVisible(true);
    }//GEN-LAST:event_ampavailablebooksActionPerformed

    private void ampnewbooksActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ampnewbooksActionPerformed
        // TODO add your handling code here:
        setVisible(false);
        AddBookPage menu = new AddBookPage();
        menu.setVisible(true);
    }//GEN-LAST:event_ampnewbooksActionPerformed

    private void amplandedbooksActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_amplandedbooksActionPerformed
        // TODO add your handling code here:
        setVisible(false);
        LendedBooksPage menu = new LendedBooksPage();
        menu.setVisible(true);
    }//GEN-LAST:event_amplandedbooksActionPerformed

    private void ampwaitingActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ampwaitingActionPerformed
        // TODO add your handling code here:
        setVisible(false);
        WaitingQueuePage menu = new WaitingQueuePage();
        menu.setVisible(true);
    }//GEN-LAST:event_ampwaitingActionPerformed

    private void ampdeletebooksActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ampdeletebooksActionPerformed
        // TODO add your handling code here:
        setVisible(false);
        DeleteBooksPage menu = new DeleteBooksPage();
        menu.setVisible(true);
    }//GEN-LAST:event_ampdeletebooksActionPerformed

    private void ampdismissActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ampdismissActionPerformed
        // TODO add your handling code here:
        setVisible(false);
        DismissStudentPage menu = new DismissStudentPage();
        menu.setVisible(true);
    }//GEN-LAST:event_ampdismissActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(AdminMenuPage.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(AdminMenuPage.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(AdminMenuPage.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(AdminMenuPage.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new AdminMenuPage().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton ampavailablebooks;
    private javax.swing.JButton ampdeletebooks;
    private javax.swing.JButton ampdismiss;
    private javax.swing.JButton amplandedbooks;
    private javax.swing.JButton amplevy;
    private javax.swing.JButton amplogout;
    private javax.swing.JButton ampnewbooks;
    private javax.swing.JButton ampstudentsowing;
    private javax.swing.JButton ampwaiting;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JSeparator jSeparator1;
    // End of variables declaration//GEN-END:variables
}