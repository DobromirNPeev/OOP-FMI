#include <iostream>
#include "Playlist.h"

int main()
{
    Playlist playlist("Chalga mix");
    playlist.addSong("Kum vratata", "Emanuela & Aneliq", 0, 2, 52, "Op op i kum vratata ne ti minavat nomerata");
    playlist.addSong("GPS-A", "Dessita & Lidia ft. Tedi Aleksandrova", 0, 3, 35, "GPS-a ni ma namiaraaa");
    playlist.addSong("HABIBI", "BOBO ARMANI x NIKI KOTICH", 0, 3, 8, "Kai ko stava habibi za nad pishat po debelite knigi");
    playlist.playSongs();
    playlist.printSongs();
    playlist.printLength();
    playlist.removeSong("HABIBI");
    playlist.printSongs();
    playlist.addSong("HABIBI", "BOBO ARMANI x NIKI KOTICH", 0, 3, 8, "Kai ko stava habibi za nad pishat po debelite knigi");
    playlist.printSongs(2);
}