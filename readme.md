# Struktura Projektu - Miniprojekt 1 (Listy)

Projekt realizuje własną implementację wybranych struktur danych w języku C++ oraz moduł badawczy do analizy ich złożoności czasowej. Program opiera się na paradygmacie obiektowym z wykorzystaniem interfejsów (szablonów) i jest podzielony na pliki nagłówkowe (`*.hpp`) oraz źródłowe (`*.cpp`). Podstawowym typem danych w strukturach jest 4-bajtowa liczba całkowita.

## 1. Drzewo Projektu

```text
├── src/
│   ├── main.cpp
│   ├── IList.hpp
│   ├── ArrayList.hpp
│   ├── ArrayList.cpp
│   ├── SinglyLinkedList.hpp
│   ├── SinglyLinkedList.cpp
│   ├── DoublyLinkedList.hpp
│   ├── DoublyLinkedList.cpp
│   ├── Menu.hpp
│   ├── Menu.cpp
│   ├── Benchmark.hpp
│   ├── Benchmark.cpp
│   ├── DataHandler.hpp
│   └── DataHandler.cpp
├── data/
│   ├── random_data_5000.txt
│   ├── random_data_10000.txt
│   └── ... 
└── README.md
```

## 2. Szczegółowy Opis Plików i Modułów

### A. Abstrakcja i Interfejsy
`IList.hpp` Abstrakcyjna klasa bazowa (interfejs) wykorzystująca szablony (template). Definiuje wirtualne metody wspólne dla wszystkich badanych struktur: dodawanie i usuwanie (początek, koniec, losowe miejsce), wyszukiwanie elementu oraz metody pomocnicze (wyświetlanie, czyszczenie struktury, pobieranie rozmiaru).

### B. Struktury Danych (Moduły implementacyjne)
`ArrayList.hpp` / `ArrayList.cpp`
Implementacja tablicy dynamicznej (ArrayList). Posiada z góry zadany rozmiar, a w momencie braku miejsca powiększa się dwukrotnie. Zarządza własną, dynamiczną alokacją pamięci.

`SinglyLinkedList.hpp` / `SinglyLinkedList.cpp`
Implementacja listy jednokierunkowej. Opiera się na dwóch wskaźnikach: head oraz tail. Posiada własną strukturę węzła (Node).
DoublyLinkedList.hpp / DoublyLinkedList.cpp
Implementacja listy dwukierunkowej (wymagana na ocenę 4.0-5.0). Posiada strukturę węzła ze wskaźnikami na następny i poprzedni element.

### C. Logika Aplikacji i Interfejs Użytkownika
`Menu.hpp` / `Menu.cpp`
Moduł obsługujący interakcję z użytkownikiem. Realizuje dwupoziomowe menu: wybór struktury danych, a następnie wybór operacji. Udostępnia opcje: zbuduj z pliku, usuń, dodaj, znajdź, utwórz losowo oraz wyświetl.

`main.cpp`
Główny plik wejściowy programu. Służy wyłącznie do inicjalizacji modułu Menu i uruchomienia pętli głównej programu. Unika stosowania zmiennych globalnych.

### D. Narzędzia Badawcze i Zarządzanie Danymi
`DataHandler.hpp` / `DataHandler.cpp`
Moduł odpowiedzialny za wczytywanie i generowanie danych. Odpowiada za wcześniejsze generowanie plików *.txt z losowymi danymi, które są wczytywane do struktur. Wykorzystuje generator pseudolosowy z zadanym ziarnem (seed) w celu zapewnienia powtarzalności wyników.

`Benchmark.hpp` / `Benchmark.cpp`
Kluczowy moduł służący do przeprowadzania badań numerycznych. Mierzy czas poszczególnych operacji w nanosekundach. Realizuje testy dla co najmniej 8 punktów pomiarowych (rozmiarów struktur nie mniejszych niż 5000 elementów). Tworzy kilkadziesiąt kopii badanej struktury przed pomiarem, aby poprawnie zmierzyć czas operacji dla danego rozmiaru (bez jego trwałego zmieniania w trakcie pojedynczego testu). Uśrednia wyniki zebranych próbek w celu wyznaczenia przypadku średniego (average-case).

### E. Katalog Danych
`data/` (katalog)
Folder przechowujący wcześniej wygenerowane pliki *.txt z losowymi danymi testowymi. Pozwala to na napełnienie tablicy i obydwu list dokładnie takim samym zestawem danych podczas testów porównawczych.
