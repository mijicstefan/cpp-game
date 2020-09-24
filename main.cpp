/** \mainpage
 *
 * \section opis Kratak opis
 *
 * Dokumentacija implementacije jednostavne RPG video igre.
 *
 * \section podesavanje Podešavanje okruženja
 *
 * \subsection zavisnosti Dobavljanje zavisnosti
 * Preuzeti [SDL2 biblioteku](http://libsdl.org/download-2.0.php), development verziju za odgovarajuci compiler.
 * Ako je instaliran Code::Blocks sa compiler-om potrebno je preuzeti mingw verziju biblioteke.
 *
 * Preuzeti proširenja biblioteke za rad sa fontovima, [SDL_TTF](http://libsdl.org/projects/SDL_ttf/),
 * i slikama, [SDL_image](http://libsdl.org/projects/SDL_image/). Kao i za osnovnu biblioteku
 * preuzeti development verzije za odgovarajući compiler.
 *
 * Otpakovati 32bit verziju osnovne biblioteke, počinje nazivom i686. Otpakovati 32bit verzije
 * proširennja osnovne biblioteke. Sadržaj direktorijuma bin, include i lib iz ovih biblioteka
 * kopirati u bin, include i lib datoteke u osnovnoj biblioteci.
 *
 * \subsection uvezivanje Uvezivanje zavisnosti
 * Napomena: Ovaj deo uputstva važi za Code::Blocks razvojno okruženje na Microsoft Windows operativnom sistemu.
 *
 * Otvoriti podešavanja za kompajliranje projekta, Project -> Build options. U levom prikazu stabla
 * odabrati da se podešavanja odnose na sve ciljne verzije, odnosno odabrati koren stabla.
 * \image html step1.png
 * Nakon toga odabrati karticu Linker settings. U desnom polju za unos, Other linker settings uneti
 * spisak biblioteka koje linker treba da uveže u konačanu izvršnu datoteku:
 * ```
 * -lmingw32
 * -lSDL2main
 * -lSDL2
 * -lSDL2_ttf
 * -lSDL2_image
 * ```
 * Primer ispravno popunjenih podešavanja za linker dat je na slici ispod.
 * \image html step2.png
 * Nakon popunjavanja podešavanja za linker preći na dodavanje putanja do zaglavlja i kompajliranih
 * biblioteka. Ova podešavanja se nalaze u kartici Search directories. U ovoj kartici prvo odabrati
 * karticu Compiler i potom kliknuti na dugme Add i odabrati putanju do zaglavlja SDL2 biblioteke,
 * direktorijum include. Potvrditi izbor i putanju sačuvati bilo kao relativnu ili apsolutnu. Primer
 * ispravno podešene putanje do direktorijuma sa zaglavljima SDL2 biblioteke, uz pretpostavku da je
 * izabrano da se putanja sačuva kao relativna i da se SDL2 biblioteka nalazi dva direktorijuma iznad
 * samog projekta, dat je na slici ispod.
 * \image html step3.png
 * Sličan postupak ponoviti i za kompajlirane biblioteke. Prvo odabrati karticu Linker a potom dodati
 * putanju do lib direktorijuma u SDL2 biblioteci. Primer dodate pitanje do kompajliranih biblioteka,
 * uz iste pretpostavke kao i za dodavanje putanja do direktorijuma sa zaglavljima, dat je na slici ispod.
 * \image html step4.png
 * Nakon ovoga sačuvati podešavanja klikom na dugme Ok.
 *
 * Poslednji korak konfigurisanja projekta jeste obezbeđivanje svih biblioteka koje se dinamički uvezuju,
 * DLL datoteka. Sve DLL datoteke iz bin direktorijuma SDL2 biblioteke potrebno je kopirati u koren projekta.
 * Nakon kopiranja datoteka koren projekta treba da sadrži sledeće .dll datoteke:
 * ```
 * libfreetype-6.dll
 * libjpeg-9.dll
 * libpng16-16.dll
 * libtiff-5.dll
 * libwebp-7.dll
 * SDL2.dll
 * SDL2_image.dll
 * SDL2_ttf.dll
 * zlib1.dll
 * ```
 * Nakon ovog koraka projekat je konačno moguće kompajlirati i pokrenuti.
 */

#include <iostream>
#include <fstream> /** Zaglavlje biblioteke za rad sa file stream-ovima. */

#include "engine.h"
#include "level.h"
#include "sprite.h"

using namespace std;

/** \brief Funkcija od koje otpočinje izvršavanje programa.
 *
 * \param argc Broj ulaznih argumenata.
 * \param argv Niz stringova koji predstavljaju ulazne argumente.
 * \return Ceo broj koji predstavlja kod greške. Ukoliko je vraćena vrednost 0 znači da nije došlo do greške.
 *
 */
int main(int argc, char** argv)
{
    Engine *eng = new Engine("Pursue Game");

    eng->addTileset("resources/tilesets/grass_tileset.txt", "default"); /** Dodavanje novog tileset-a. */

    ifstream levelStream("resources/levels/level1.txt");
    eng->addDrawable(new Level(levelStream, eng->getTileset("default"))); /** Dodavanje novog nivoa. */



    eng->run(); /** Pokretanje glavne petlje igre. */
    delete eng; /** Oslobadjanje memorije koju je zauzela instanca Engine klase. */
    return 0;
}
