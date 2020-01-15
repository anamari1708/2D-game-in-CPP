Realizirana je igra Swaglords of space unutar koje se uni�tavaju neprijateljski objekti u razli�itim veli�inama i bojama kvadrata,
a programski jezik koji je kori�ten je C++ u razvojnom okru�enju Visual Studio.
Koristi se SFML datoteka.
SFML (engl. Simple and Fast Multimedia Library) je multimedijalna, vi�eplatformna i vi�ejezi�na bibilioteka.
SFML pru�a jednostavno su�elje za razli�ite komponente ra�unala kako bi olak�ao razvoj igara i multimedijalnih aplikacija.

Logika igre:
Kada se igra pokrene, nalazimo se unutar svemira (crna pozadina) i dolaze neprijateljski objekti
u obliku kvadrata razli�itih veli�ina i boja.
U realnom vremenu vidi se broj �ivota (Health) i broj ostvarenih bodova (Points) .
Poeni se posti�u tako da se kliknem mi�em na �to ve�i broj kvadrata koji se random
pojavljuju po ekranu i brzo padaju prema dolje.
Za svaki kvadrat koji padne, a ne prije�e se mi�em preko njega, gubi se jedan �ivot.
�to je kvadrat manji, to donisi vi�e bodova. Svaki kvadrat druge boje donosi druga�iji broj bodova.
Cilj igre je ostvariti �to vi�e bodova, tj uhvatiti mi�em �to vi�e kvadrata prije nego se ne potro�e svi �ivoti.
 