/**
 * @file FenetrePrincipale.java
 * @author Bérénice Nghiêm (berenice.nghiem@telecom-paris.fr)
 */


import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;


/**
 * @class FenetrePrincipale
 * @brief Classe créant l'interface graphique Java/Swing
 * 
 * Classe principale créant une fenêtre avec une zone de texte, une barre de menus, une barre d'outils,
 * et permettant une interaction client/serveur pour rechercher et jouer des objets multimédias.
 */
public class FenetrePrincipale extends JFrame {

    private static final long serialVersionUID = 1L;
    private JTextArea textArea;
    private JTextField searchField;
    private JTextField playField;
    private Socket socket;
    private PrintWriter out;
    private BufferedReader in;

    /**
     * @brief Constructeur initialisant l'interface graphique.
     */
    public FenetrePrincipale() {
        setTitle("Fenêtre Principale avec Interacteurs");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        System.setProperty("apple.laf.useScreenMenuBar", "true");

        // Zone de texte avec ascenseurs
        textArea = new JTextArea(10, 30);
        textArea.setEditable(false);
        JScrollPane scrollPane = new JScrollPane(textArea);
        add(scrollPane, BorderLayout.CENTER);

        // Panneau pour les champs de recherche et de lecture
        JPanel inputPanel = new JPanel(new GridLayout(2, 2, 5, 5));
        searchField = new JTextField();
        JButton searchButton = new JButton("Rechercher");
        playField = new JTextField();
        JButton playButton = new JButton("Jouer");

        inputPanel.add(new JLabel("Rechercher un objet :"));
        inputPanel.add(searchField);
        inputPanel.add(searchButton);
        inputPanel.add(new JLabel("Jouer un objet :"));
        inputPanel.add(playField);
        inputPanel.add(playButton);

        add(inputPanel, BorderLayout.SOUTH);

        // Actions des boutons
        searchButton.addActionListener(e -> rechercherObjet());
        playButton.addActionListener(e -> jouerObjet());

        // Barre de menus
        JMenuBar menuBar = new JMenuBar();
        JMenu menu = new JMenu("Actions");
        menu.add(new JMenuItem(new AjouterLigneAction("Ajouter ligne 1", "Ligne ajoutée par le bouton 1\n")));
        menu.add(new JMenuItem(new AjouterLigneAction("Ajouter ligne 2", "Ligne ajoutée par le bouton 2\n")));
        menu.add(new JMenuItem(new QuitterAction("Quitter")));
        menuBar.add(menu);
        setJMenuBar(menuBar);

        // Barre d'outils
        JToolBar toolBar = new JToolBar();
        toolBar.add(new JButton(new AjouterLigneAction("Ajouter ligne 1", "Ligne ajoutée par le bouton 1\n")));
        toolBar.add(new JButton(new AjouterLigneAction("Ajouter ligne 2", "Ligne ajoutée par le bouton 2\n")));
        toolBar.add(new JButton(new QuitterAction("Quitter")));
        add(toolBar, BorderLayout.NORTH);
        
        // Connexion au serveur C++
        try {
            socket = new Socket(Client.DEFAULT_HOST, Client.DEFAULT_PORT);
            out = new PrintWriter(socket.getOutputStream(), true);
            in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            textArea.append("Connecté au serveur.\n");
        } catch (Exception e) {
            JOptionPane.showMessageDialog(this, "Impossible de se connecter au serveur : " + e.getMessage(), "Erreur", JOptionPane.ERROR_MESSAGE);
            System.exit(1);
        }

        // Ajustement de la fenêtre
        pack();
        setLocationRelativeTo(null);
        setVisible(true);
    }


    /**
    * @brief Méthode pour rechercher un objet multimédia sur le serveur
    */
    private void rechercherObjet() {
        String objet = searchField.getText().trim();
        if (!objet.isEmpty()) {
            envoyerCommande("find media " + objet);
        } else {
            JOptionPane.showMessageDialog(this, "Veuillez entrer un nom d'objet à rechercher.", "Information", JOptionPane.INFORMATION_MESSAGE);
        }
    }

    /**
     * @brief Métode pour jouer un objet multimédia sur le serveur.
     */
    private void jouerObjet() {
        String objet = playField.getText().trim();
        if (!objet.isEmpty()) {
            envoyerCommande("play " + objet);
        } else {
            JOptionPane.showMessageDialog(this, "Veuillez entrer un nom d'objet à jouer.", "Information", JOptionPane.INFORMATION_MESSAGE);
        }
    }

    /**
     * @brief Méthode pour envoier une commande au serveur et affiche la réponse.
     * 
     * @param commande La commande à envoyer.
     */
    private void envoyerCommande(String commande) {
        try {
            out.println(commande);
            String reponse = in.readLine();
            textArea.append("\nRéponse du serveur : " + reponse);
        } catch (Exception e) {
            textArea.append("\nErreur de communication avec le serveur : " + e.getMessage());
        }
    }

    /**
     * @brief Classe interne pour ajouter une ligne de texte.
     */
    private class AjouterLigneAction extends AbstractAction {
        private static final long serialVersionUID = 1L;
        private final String message;

        public AjouterLigneAction(String nom, String message) {
            super(nom);
            this.message = message;
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            textArea.append(message);
        }
    }

    /**
     * @brief Classe interne pour quitter l'application.
     */
    private class QuitterAction extends AbstractAction {
        private static final long serialVersionUID = 1L;

        public QuitterAction(String nom) {
            super(nom);
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            try {
                if (socket != null) socket.close();
            } catch (Exception ex) {
                System.err.println("Erreur lors de la fermeture de la connexion : " + ex.getMessage());
            }
            System.exit(0);
        }
    }

    /**
     * @brief Méthode principale pour lancer l'application.
     * 
     * @param args Arguments de la ligne de commande (non utilisés ici).
     */
    public static void main(String[] args) {
        SwingUtilities.invokeLater(FenetrePrincipale::new);
    }
}