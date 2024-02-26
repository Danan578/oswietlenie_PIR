Projekt zacząłem na początku 2024r. na zlecenie mojej siostry.
Głównym założeniem projektu jest nimimalny budżet do wykonania oświetlenia schodów.
Uruchomienie oświetlenia po zmierzchu (fotorezystor) za pomącą czujnika PIR HC-SR501 z ustawionym wyjściem retriggering.
Na wyściu każdego paska LED tranzystor N-mosfet.
Ograniczona moc i jasność. Paski led uruchamiane są z częstotliwością 100Hz pojedynczo, w parach lub zestawie (3szt. max 6szt.) w zależnośći od jasności w celu ograniczenia mocy zasilacza (w tym kosztów całego projektu).
Jasność oświetlenia 100% możliwa tylko w wersji prototypowej.
Uruchomienie oświetlenia zaczyna się animacją zapalającą kolejne ledy w zależnośći z którego czujnika zostały uruchomione.
Czas oświetlenia zależy od czasu wyzwolenia ustawionego indywidualnie dla każdego czujnika w module czujnika PIR.
