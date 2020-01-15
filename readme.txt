Realizirana je igra Swaglords of space unutar koje se uništavaju neprijateljski objekti u razlièitim velièinama i bojama kvadrata,
a programski jezik koji je korišten je C++ u razvojnom okruženju Visual Studio.
Koristi se SFML datoteka.
SFML (engl. Simple and Fast Multimedia Library) je multimedijalna, višeplatformna i višejezièna bibilioteka.
SFML pruža jednostavno suèelje za razlièite komponente raèunala kako bi olakšao razvoj igara i multimedijalnih aplikacija.

Logika igre:
Kada se igra pokrene, nalazimo se unutar svemira (crna pozadina) i dolaze neprijateljski objekti
u obliku kvadrata razlièitih velièina i boja.
U realnom vremenu vidi se broj života (Health) i broj ostvarenih bodova (Points) .
Poeni se postižu tako da se kliknem mišem na što veæi broj kvadrata koji se random
pojavljuju po ekranu i brzo padaju prema dolje.
Za svaki kvadrat koji padne, a ne prijeðe se mišem preko njega, gubi se jedan život.
Što je kvadrat manji, to donisi više bodova. Svaki kvadrat druge boje donosi drugaèiji broj bodova.
Cilj igre je ostvariti što više bodova, tj uhvatiti mišem što više kvadrata prije nego se ne potroše svi životi.
 