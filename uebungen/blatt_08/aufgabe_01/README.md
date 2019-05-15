# Aufgabe 01 (Binäre Suchbäume und AVL-Bäume)

## a)

Der Nachfolger eines Inorder-Nachfolgers eines Knotens mit zwei Nachfolgern hat maximal 1. Nachfolger.

1. Fall: Der Knoten hat einen linken Knoten, dann geht man weiter zu diesem.
2. Fall: Man kommt zu einem Knoten der keinen Linken Nachfolger hat:
    1. Fall: Der Knoten hat **keinen** rechten Nachfolger: Man hat also den Inorder Nachfolger in einem Blatt gefunden.
    2. Fall: Der Knoten hat **einen** rechten Nachfolger: Da dieser Knoten allerdings der rechte Nachfolger ist, ist dessen Wert größer als der des aktuellen Knotens. Somit ist der aktuelle Knoten der Inorder Nachfolger.

Folgerung:

    Entweder gefunden in Blatt (keine Nachfolger) oder in Knick, dann gibt es einen Nachfolger.