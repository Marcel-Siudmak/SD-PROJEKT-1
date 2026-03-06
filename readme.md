# Miniprojekt 1 - Struktury Danych

Projekt realizuje własną implementację wybranych struktur danych w języku C++ oraz moduł badawczy do analizy ich złożoności czasowej. Program opiera się na paradygmacie obiektowym z wykorzystaniem interfejsów (szablonów) i jest podzielony na pliki nagłówkowe (`*.hpp`) oraz źródłowe (`*.cpp`). Podstawowym typem danych w strukturach jest 4-bajtowa liczba całkowita.

## Spis treści
* [Wymagania](#1-wymagania)
* [Kompilacja i uruchomienie](#2-kompilacja-i-uruchomienie)
* [Struktura Projektu](#3-struktura-projektu)
* [Szczegółowy Opis Plików i Modułów](#4-szczegółowy-opis-plików-i-modułów)

## 1. Wymagania
* **Kompilator:** GCC 15+ / Clang 17+ (wymagane wsparcie dla C++20)
* **System budowania:** CMake 3.10+
* **System operacyjny:** macOS / Windows / Linux

## 2. Kompilacja i uruchomienie
Aby zbudować projekt, wykonaj poniższe kroki w terminalu:

1. Stwórz folder budowania:
   ```bash
   mkdir build && cd build
   ```

2. Skonfiguruj projekt za pomocą CMake:
   ```bash
   cmake ..
   ```

3. Skompiluj:
   ```bash
   cmake --build .
   ```

4. Uruchom program:
   ```bash
   ./mini_projekt_1
   ```

## 3. Struktura Projektu

```text
├── src/
│   ├── `main.cpp` - Główny plik programu
│   ├── `IList.hpp` - Abstrakcyjna klasa bazowa (interfejs)
│   ├── `ArrayList.hpp` - Implementacja tablicy dynamicznej
│   ├── `ArrayList.cpp` - Implementacja tablicy dynamicznej
│   ├── `SinglyLinkedList.hpp` - Implementacja listy jednokierunkowej
│   ├── `SinglyLinkedList.cpp` - Implementacja listy jednokierunkowej
│   ├── `DoublyLinkedList.hpp` - Implementacja listy dwukierunkowej
│   ├── `DoublyLinkedList.cpp` - Implementacja listy dwukierunkowej
│   ├── `Menu.hpp` - Menu aplikacji
│   ├── `Menu.cpp` - Menu aplikacji
│   ├── `Benchmark.hpp` - Narzędzie do pomiaru wydajności
│   ├── `Benchmark.cpp` - Narzędzie do pomiaru wydajności
│   ├── `DataHandler.hpp` - Narzędzie do generowania i wczytywania danych
│   └── `DataHandler.cpp` - Narzędzie do generowania i wczytywania danych
├── data/
│   ├── `random_data_5000.txt` - Plik z danymi testowymi
│   ├── `random_data_10000.txt` - Plik z danymi testowymi
│   └── ... 
├── build/
│   ├── `binary` - Plik wykonywalny
│   └── ...
├── `CMakeLists.txt` - Plik konfiguracyjny CMake
└── `README.md` - Plik README
```

## 4. Szczegółowy Opis Plików i Modułów

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
