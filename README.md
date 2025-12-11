## **🤖 Projet Robot Bluetooth Arduino (HC-05 & L298N)**

Un projet de robot mobile à quatre roues piloté à distance via une communication série Bluetooth (module HC-05) et contrôlé par une carte Arduino Uno.

Ce projet est idéal pour apprendre les bases de la robotique, du contrôle de moteurs DC et de la communication sans fil avec l'Arduino.

### **⚙️ Matériel Requis**

Ce projet nécessite les composants physiques suivants :

* **Microcontrôleur :** Carte Arduino Uno  
* **Contrôleur de Moteur :** Driver de Moteur L298N (double pont en H)  
* **Communication sans fil :** Module Bluetooth HC-05 (ou HC-06)  
* **Alimentation :** Batterie de 16V (pour alimenter les moteurs)  
* **Châssis et mobilité :**  
  * 4 Roues et 4 Moteurs à Bobines (moteurs DC)  
  * Double support en plexiglas (châssis du robot)

### **🔌 Schéma de Connexion (Câblage)**

#### **Moteurs et Driver L298N**

Le driver L298N est connecté à l'Arduino pour contrôler la direction et la vitesse des deux paires de moteurs (Moteur 1 \= Roues Gauches, Moteur 2 \= Roues Droites).

| Fonction | Broche Arduino | Variable dans le code (finission.ino) |
| :---- | :---- | :---- |
| Moteur 1 \- Entrée 1 (Direction) | 2 | IN1 |
| Moteur 1 \- Entrée 2 (Direction) | 3 | IN2 |
| Moteur 2 \- Entrée 1 (Direction) | 4 | IN3 |
| Moteur 2 \- Entrée 2 (Direction) | 5 | IN4 |
| **Vitesse Moteur 1 (PWM)** | **6 (PWM)** | ENA |
| **Vitesse Moteur 2 (PWM)** | **9 (PWM)** | ENB |

#### **Communication Bluetooth (HC-05)**

Le code utilise la **liaison série matérielle** de l'Arduino, ce qui signifie que le module HC-05 doit être connecté aux broches 0 et 1\.

**Règle d'or : TX doit toujours se connecter à RX et vice-versa \!**

| Côté Arduino | Côté Bluetooth (HC-05) | Rôle |
| :---- | :---- | :---- |
| **Broche 1 (TX \- Transmission)** | **Broche RX** (Réception) | L'Arduino envoie des données vers le HC-05. |
| **Broche 0 (RX \- Réception)** | **Broche TX** (Transmission) | Le HC-05 envoie des données vers l'Arduino. |

**ATTENTION :** Lorsque le module HC-05 est connecté aux broches 0 et 1, vous devez **déconnecter** le module Bluetooth avant de téléverser le code sur l'Arduino, car ces broches sont également utilisées par le port USB.

### **💻 Commandes et Fonctionnement du Code**

Le programme Arduino écoute les commandes reçues via le port série à un débit de **9600 bauds**.

| Commande Bluetooth | Caractère de commande | Description du mouvement |
| :---- | :---- | :---- |
| Avancer | F | Les deux paires de moteurs tournent en avant. |
| Reculer | B | Les deux paires de moteurs tournent en arrière. |
| Tourner à Gauche | L | Moteur Gauche (Moteur 1\) en avant, Moteur Droit (Moteur 2\) à l'arrêt. |
| Tourner à Droite | R | Moteur Gauche (Moteur 1\) à l'arrêt, Moteur Droit (Moteur 2\) en avant. |
| Arrêter | S | Tous les moteurs s'arrêtent. |

La vitesse est fixée à 250 (sur 255\) dans les fonctions de mouvement (forware(), backware(), etc.) via les broches PWM ENA et ENB.

### **🚀 Guide de Démarrage Rapide**

1. **Câblage :** Finaliser le montage du châssis et effectuer toutes les connexions électriques et de signal.  
2. **Téléversement :** Déconnecter le module HC-05, puis téléverser le fichier finission.ino sur l'Arduino.  
3. **Connexion :** Reconnecter le module HC-05.  
4. **Appairage :** Appairer le module HC-05 avec votre téléphone ou tablette (généralement le mot de passe est 1234 ou 0000).  
5. **Contrôle via application mobile :**  
   * Utilisez l'application **Bluetooth RC Controller** (ou une application similaire qui permet l'envoi de caractères personnalisés).  
   * Configurez les boutons de l'application pour envoyer les commandes de caractère unique (F, B, L, R, S) correspondantes pour piloter le robot.
