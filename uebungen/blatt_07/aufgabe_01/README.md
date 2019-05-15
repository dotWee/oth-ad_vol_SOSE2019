# Aufgabe 01 (Quicksort)

Der Quellcode zur Datenstruktur einer verketteten Suchliste in C++ kann in [Suchliste.h](Suchliste.h) eingesehen werden.

    Notiz: Eine rekursiven Löschung eines Elements aus der Liste ist (noch) nicht implementiert.

## Iterative Löschung

```cpp
void removeElementIterativ(int value) {
    Element* temp;
    Element* prev = NULL;
    Element* next;

    for (temp = first;  temp != NULL; temp = next) {
        next = temp->next;

        if (temp->value != value) {
            prev = temp;
            continue;
        }

        if (prev != NULL) {
            prev->next = next;
        }
        else {
            first = next;
        }

        delete temp;
    }
}
```